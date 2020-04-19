#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include <chrono>
using namespace std;

int main(int argc, char* argv[])
{
    int testData[40000];
    float insert[400];
    float search[400];
    ifstream LinkedListTestData(argv[1]);
    if (LinkedListTestData.fail())
    {
        return -1;
    }
    else
    {
        string line;
        string number; 
        int idx = 0; 
        LinkedList LL;
        while (getline(LinkedListTestData, line, ','))
        {
            testData[idx] = stoi(line);
            idx++;
        }
        int insertElements = 1;
        int numEntries = 0;
        int i = 0;
        while (numEntries < 40000)
        {
            auto start = std::chrono::system_clock::now();
            LL.insert(NULL, testData[numEntries]); 
            while (insertElements < 100)
            {
                
                LL.insert(LL.searchList(testData[insertElements-1]), testData[insertElements]);
                //LL.printList();
                insertElements++;
            }
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start;
            insert[i] = (elapsed_seconds.count())/(100);
            //i++;
            numEntries += 100;
        }
        for (int i = 0; i < 400; i++)
        {
            cout << insert[i] << endl;
        }
    }
}