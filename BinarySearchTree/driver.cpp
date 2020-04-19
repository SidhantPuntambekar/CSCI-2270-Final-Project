#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "BST.hpp"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    int testData[40000];
    float insert[400];
    float search[400];
    ifstream BSTTestData(argv[1]);
    if (BSTTestData.fail())
    {
        return -1;
    }
    else
    {
        string line;
        string number; 
        int idx = 0; 
       
        while (getline(BSTTestData, line, ','))
        {
            testData[idx] = stoi(line);
            idx++;
        }
        int insertElements = 0;
        BST mailData;
        int numEntries = 0;
        while (numEntries < 40000)
        {
            high_resolution_clock::time_point startInsert = high_resolution_clock::now();
            mailData.addNode(testData[numEntries]); 
            for (int i = numEntries; i < numEntries + 100; i++)
            {
                mailData.addNode(testData[i]);
            }
            high_resolution_clock::time_point endInsert = high_resolution_clock::now();
            duration<double> execTimeInsert = duration_cast<microseconds>(endInsert - startInsert);
            insert[numEntries/100] = (execTimeInsert.count())/100;
            numEntries += 100;
        }
        for (int i = 0; i < 400; i++)
        {
            cout << insert[i] << endl;
        }
    }
}