#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "hash.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

//perform insert and search for chaining, linear, quadratic

int main(int argc, char* argv[])
{
    srand(0);
    int testData[40000];
    float insert[400];
    float search[400];
    //vector<float> randomNumbers[40000];
    ifstream HashTestData(argv[1]);
    if (HashTestData.fail())
    {
        return -1;
    }
    else
    {
        string line;
        string number; 
        int idx = 0; 
        cout<<"Constructing table"<<endl;
        HashTable HashTable(40000);
        while (getline(HashTestData, line, ','))
        {
            
            testData[idx] = stoi(line); //storing values from csv file
            idx++;
        }
        int insertElements = 1;
        int numEntries = 0;

        ofstream results; //Create output file stream of results
        results.open("resultsQuadraticProbing.csv", std::ios_base::app);
        results<<"Quadratic Probing collisions: "<<endl;
        while (numEntries < 40000)
        {
            //Insert
           // cout<<"collisions: "<<HashTable.getNumOfCollision()<<" ";
           
            high_resolution_clock::time_point startInsert = high_resolution_clock::now();
            for (int i = numEntries; i < numEntries + 100; i++)
            {
                
                HashTable.quadraticProb(testData[i]); //insert via linear prob
               
                //then print num collisions
                if(i%100==0){
                    cout<<"collisions: "<<HashTable.getNumOfCollision()<<" ";
                    results<<HashTable.getNumOfCollision()<<",";
                }
                
                
                
            }
            high_resolution_clock::time_point endInsert = high_resolution_clock::now();
            duration<double> execTimeInsert = duration_cast<microseconds>(endInsert - startInsert);
            insert[numEntries/100] = (execTimeInsert.count())/100;

            //Search
            high_resolution_clock::time_point startSearch = high_resolution_clock::now();
            for (int i = 0; i < 100; i++)
            {
                int index = rand()%(numEntries+1);
                node* ptr = HashTable.searchItemQuadtratic(testData[index]);
            }
            high_resolution_clock::time_point endSearch = high_resolution_clock::now();
            duration<double> execTimeSearch = duration_cast<microseconds>(endSearch - startSearch);
            search[numEntries/100] = (execTimeSearch.count())/100;
            numEntries += 100;
        }

        results<<endl<<endl;
         //Write to results.txt
        results << "Insert Quadratic Probing Times" << endl;
        for (int i = 0; i < 400; i++)
        {
            results << insert[i] << ",";
            
        }
        results << endl;
        results << "Search Quadratic Probing Times" << endl;
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
        
       cout<<"collisions: "<<HashTable.getNumOfCollision()<<endl;
    }
}
