#include <iostream>
#include <limits>
#include <fstream> //Include fstream for getline
#include <sstream> //Include stringstream
#include <stdlib.h>
#include "LinkedList.h"
#include <chrono> //Include chrono library for timing
using namespace std;
using namespace std::chrono; //Add namespace for chrono library for timing

int main(int argc, char* argv[])
{
    srand(0); //Seed random value starting at zero
    int testData[40000]; //Create array of data points for input data set
    float insert[400]; //Insert array to track times of inserting records
    float search[400]; //Search array to track times of searching for records
    ifstream LinkedListTestData(argv[1]); //Create input file stream for argument 1 (csv file) in command line arg
    if (LinkedListTestData.fail()) //If the file fails to open
    {
        return -1; //Return -1
    }
    else //If the file opens
    {
        string line; //Create string var to keep track of line in csv
        //string number; 
        int idx = 0; //Keep track of index in testData array for use in while loop 
        LinkedList LL; //Create new linked list object. For implementation, see header and LinkedList.cpp
        while (getline(LinkedListTestData, line, ',')) //Use getline and separate each line at comma delimiter
        {
            testData[idx] = stoi(line); //Convert line to integer and store in testData array
            idx++; //Increase index by 1
        }
        //int insertElements = 1;
        int numEntries = 0; //Keeps track of entries 100 at time 
        
        while (numEntries < 40000) //Loop until numEntries is as long as data file length
        {
            //Insert
            high_resolution_clock::time_point startInsert = high_resolution_clock::now(); //Start chrono clock
            for (int i = numEntries; i < numEntries + 100; i++) //Loop through from numEntries to numEntries + 100
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
                LL.insert(testData[i]); //Insert testData[i] into the Linked List
            }
            high_resolution_clock::time_point endInsert = high_resolution_clock::now(); //Stop clock
            duration<double> execTimeInsert = duration_cast<microseconds>(endInsert - startInsert); //Calculate elapsed time
            insert[numEntries/100] = (execTimeInsert.count())/100; //Average and store in insert array

            //Search
            high_resolution_clock::time_point startSearch = high_resolution_clock::now(); //Start clock
            for (int i = 0; i < 100; i++) //Loop through 100 for 100 psuedo-random numbers
            {
                int index = rand()%(numEntries+1); //Generate a random number from 0 to numEntries+1
                Node* ptr = LL.searchList(testData[index]); //Search the list for the value and store in pointer to node object
            }
            high_resolution_clock::time_point endSearch = high_resolution_clock::now(); //Stop clock
            duration<double> execTimeSearch = duration_cast<microseconds>(endSearch - startSearch); //Calculate elapsed time
            search[numEntries/100] = (execTimeSearch.count())/100; //Average and store in search array
            numEntries += 100; //Increase numEntries by 100
        }

        ofstream results; //Create output file stream of results
        results.open("resultsLinkedList.csv", std::ios_base::app); //Write to resultsLinkedList.csv
        results << "Insert Linked Lists Times" << endl; //Print statement
        for (int i = 0; i < 400; i++) //Write insert to csv file
        {
            results << insert[i] << ",";
        }
        results << endl;
        results << "Search Linked Lists Times" << endl; //Print statement
        for (int i = 0; i < 400; i++)  //Write saearch to csv file
        {
            results << search[i] << ",";
        }

        cout << "Insert" << endl; 
        for (int i = 0; i < 400; i++) //Print insert results for verification
        {
            cout << insert[i] << endl;
        }
        cout << endl;
        cout << "Search" << endl;
        for (int i = 0; i < 400; i++) //Print search results for verification. 
        {
            cout << search[i] << endl;
        }
    }
}