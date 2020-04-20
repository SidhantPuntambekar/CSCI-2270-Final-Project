#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

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
        while (numEntries < 40000)
        {
            high_resolution_clock::time_point startInsert = high_resolution_clock::now();
            LL.insert(NULL, testData[numEntries]); 
            for (int i = numEntries; i < numEntries+100; i++)
            {
                LL.insert(LL.searchList(testData[i-1]), testData[i]);
            }
            high_resolution_clock::time_point endInsert = high_resolution_clock::now();
            duration<double> execTimeInsert = duration_cast<microseconds>(endInsert - startInsert)/100;
            insert[numEntries/100] = (execTimeInsert.count());

            high_resolution_clock::time_point startSearch = high_resolution_clock::now();

            numEntries += 100;
        }
        for (int i = 0; i < 400; i++)
        {
            cout << insert[i] << endl;
        }
    }
}