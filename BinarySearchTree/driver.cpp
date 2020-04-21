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
            //Insert
            high_resolution_clock::time_point startInsert = high_resolution_clock::now(); 
            for (int i = numEntries; i < numEntries + 100; i++)
            {
                mailData.addNode(testData[i]);
            }
            high_resolution_clock::time_point endInsert = high_resolution_clock::now();
            duration<double> execTimeInsert = duration_cast<microseconds>(endInsert - startInsert);
            insert[numEntries/100] = (execTimeInsert.count())/100;

            //Search
            high_resolution_clock::time_point startSearch = high_resolution_clock::now();
            for (int i = 0; i < 100; i++)
            {
                int index = rand()%(numEntries+1);
                bool found = mailData.searchKey(testData[index]);
            }
            high_resolution_clock::time_point endSearch = high_resolution_clock::now();
            duration<double> execTimeSearch = duration_cast<microseconds>(endSearch - startSearch);
            search[numEntries/100] = (execTimeSearch.count())/100;
            numEntries += 100;
        }
        ofstream results; //Create output file stream of results
        results.open("resultsBST.csv", std::ios_base::app); //Write to results.txt
        results << "Insert BST Times" << endl;
        for (int i = 0; i < 400; i++)
        {
            results << insert[i] << ",";
        }
        results << endl;
        results << "Search BST Times" << endl;
        for (int i = 0; i < 400; i++)
        {
            results << search[i] << ",";
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
    }
}