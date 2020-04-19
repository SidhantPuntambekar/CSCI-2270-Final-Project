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
            high_resolution_clock::time_point start = high_resolution_clock::now();
            LL.insert(NULL, testData[numEntries]); 
            for (int i = numEntries; i < numEntries+100; i++)
            {
                LL.insert(LL.searchList(testData[i-1]), testData[i]);
            }
            high_resolution_clock::time_point end = high_resolution_clock::now();
            duration<double> execTime = duration_cast<microseconds>(end - start);
            insert[numEntries/100] = (execTime.count());
            numEntries += 100;
        }
        for (int i = 0; i < 400; i++)
        {
            cout << insert[i] << endl;
        }
    }
}