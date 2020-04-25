#include <iostream>
#include <limits>
#include <fstream> //Include fstream for getline
#include <sstream> //Include stringstream
#include "BST.hpp"
#include <chrono> //Include chrono library for timing
using namespace std;
using namespace std::chrono; //Add namespace for chrono library for timing

int main(int argc, char* argv[])
{
    srand(0); //Seed random value starting at zero
    int testData[40000]; //Test data array
    float insert[400]; //Insert array
    float search[400]; //Search array
    ifstream BSTTestData(argv[1]); //Create input file stream for BST
    if (BSTTestData.fail()) //If the file fails to open
    {
        return -1; //Return -1
    }
    else
    {
        string line; //Keep track of line in csv
        string number; 
        int idx = 0; //Index variable
       
        while (getline(BSTTestData, line, ',')) //Call getline and separate at comma
        {
            testData[idx] = stoi(line); //Store line in test data array via stoi
            idx++; //Increase index by 1
        }
        int insertElements = 0; 
        BST mailData; //Create BST called mailData
        int numEntries = 0; //Keep track of numEntries 
        while (numEntries < 40000) //Loop till numEntries is 40000
        {
            //Insert
            high_resolution_clock::time_point startInsert = high_resolution_clock::now(); //Start clock
            for (int i = numEntries; i < numEntries + 100; i++) //Loop 100 entries at a time
            {
                mailData.addNode(testData[i]); //Insert data into the BST
            }
            high_resolution_clock::time_point endInsert = high_resolution_clock::now(); //Stop clock
            duration<double> execTimeInsert = duration_cast<microseconds>(endInsert - startInsert); //Calculate elapsed time
            insert[numEntries/100] = (execTimeInsert.count())/100; //Average and store in insert array

            //Search
            high_resolution_clock::time_point startSearch = high_resolution_clock::now(); //Start clock
            for (int i = 0; i < 100; i++) //Loop for 100 pseudorandom number
            {
                int index = rand()%(numEntries+1); //Generate random index between 0 and numEntries+1
                bool found = mailData.searchKey(testData[index]); //Store search bool var in found
            }
            high_resolution_clock::time_point endSearch = high_resolution_clock::now(); //Stop clock
            duration<double> execTimeSearch = duration_cast<microseconds>(endSearch - startSearch); //Elapsed time
            search[numEntries/100] = (execTimeSearch.count())/100; //Average and store in search array
            numEntries += 100; //Increase numEntries by 100
        }
        ofstream results; //Create output file stream of results
        results.open("resultsBSTDataSetB.csv", std::ios_base::app); //Write to resultsBST.txt
        results << "Insert BST Times" << endl; //Print statement
        for (int i = 0; i < 400; i++) //Write insert to csv file
        {
            results << insert[i] << ",";
        }
        results << endl;
        results << "Search BST Times" << endl; //Print statement
        for (int i = 0; i < 400; i++) //Write search to csv file
        {
            results << search[i] << ",";
        }
        cout << "Insert" << endl;
        for (int i = 0; i < 400; i++) //Print insert for verfication
        {
            cout << insert[i] << endl;
        }
        cout << endl;
        cout << "Search" << endl;
        for (int i = 0; i < 400; i++) //Print search for verification
        {
            cout << search[i] << endl;
        }
    }
}