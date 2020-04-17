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
        while (getline(LinkedListTestData, line, ','))
        {
            testData[idx] = stoi(line);
            idx++;
        }
        
        for (int i = 0; i < 10; i++)
        {
            cout << testData[i] << endl;
        }
    }
}