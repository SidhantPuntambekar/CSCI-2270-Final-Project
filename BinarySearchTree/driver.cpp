#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "BST.hpp"
#include <chrono>
using namespace std;

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
        auto start = std::chrono::system_clock::now();
        BST mailData(testData[0]);
        int numEntries = 0;
        while (numEntries < 40000)
        {
            while (insertElements < 100)
            {
                for (int i = 1; i < 25; i++)
                {
                    mailData.addNode(testData[i]);
                }
                //mailData.print2DUtil(1);
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end-start;
                insert[insertElements] = elapsed_seconds.count();
                insertElements++;
            }
        }
        for (int i = 0; i < 120; i++)
        {
            cout << insert[i] << endl;
        }
    }
}