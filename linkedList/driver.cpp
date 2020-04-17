#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
using namespace std;

int main(int argc, char* argv[])
{
    int testData[40000];
    float insert[400];
    float search[400];
    string openFile = argv[1];
    ifstream LinkedListTestData(openFile);
    if (LinkedListTestData.fail())
    {
        return -1;
    }
    else
    {
        string line;
        string number = 0; 
        int idx = 0; 
        while (getline(LinkedListTestData, line))
        {
            stringstream ss(line);
            while (getline(ss, number, ','))
            {
                testData[idx] = stoi(number);
                idx++;
            }
        }
        for (int i = 0; i < 25; i++)
        {
            cout << testData[i] << endl;
        }
    }
}