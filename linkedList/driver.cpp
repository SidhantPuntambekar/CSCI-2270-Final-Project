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
        int insertElements = 0;
        while (insertElements < 100)
        {
            auto start = std::chrono::system_clock::now();
            LL.insert(NULL, testData[0]); 
            for (int i = 1; i < 100; i++)
            {
                LL.insert(LL.searchList(testData[i-1]), testData[i]);
                //LL.printList();
            }
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start;
            insert[insertElements] = elapsed_seconds.count();
            insertElements++;
        }
        for (int i = 0; i < insertElements; i++)
        {
            cout << insert[i] << endl;
        }
    }
}