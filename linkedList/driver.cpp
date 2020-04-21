#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "LinkedList.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    srand(0);
    int testData[40000];
    float insert[400];
    float search[400];
    //vector<float> randomNumbers[40000];
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
            //Insert
            high_resolution_clock::time_point startInsert = high_resolution_clock::now();
            for (int i = numEntries; i < numEntries + 100; i++)
            {
                // Node* ptr;
                // if (i == 0)
                // {
                //     ptr = NULL;
                // }
                // else
                // {
                //     ptr = LL.searchList(testData[i-1]);
                // }
                LL.insert(testData[i]);
            }
            high_resolution_clock::time_point endInsert = high_resolution_clock::now();
            duration<double> execTimeInsert = duration_cast<microseconds>(endInsert - startInsert);
            insert[numEntries/100] = (execTimeInsert.count())/100;

            //Search
            high_resolution_clock::time_point startSearch = high_resolution_clock::now();
            for (int i = 0; i < 100; i++)
            {
                int index = rand()%(numEntries+1);
                Node* ptr = LL.searchList(testData[index]);
            }
            high_resolution_clock::time_point endSearch = high_resolution_clock::now();
            duration<double> execTimeSearch = duration_cast<microseconds>(endSearch - startSearch);
            search[numEntries/100] = (execTimeSearch.count())/100;
            numEntries += 100;
        }
        cout << "Insert" << endl;
        for (int i = 0; i < 400; i++)
        {
            cout << insert[i] << endl;
        }
        cout << endl;
        cout << "Search" << endl;
        for (int i = 0; i < 400; i++)
        {
            cout << search[i] << endl;
        }
        //LL.printList();
    }
}