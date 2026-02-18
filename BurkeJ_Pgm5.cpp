//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: Realtor Competition Results - Analyzes sales data for multiple
//          realtors and identifies the top performer and worst performer.
// Process: Reads realtor names and house sales from input file, handles
//          negative values by converting to absolute values, finds the
//          realtor with most and least houses sold, and displays results.
// Results: Displays all realtors with their sales, identifies the winner
//          and worst performer, and calculates total houses sold.
//
// Class: CS2010
// Section: 1003
// Term: Spring 2026
// Author: Jack Burke
//
// Reflection: The main difficulty was managing the multiple arrays and insuring that each array properly stores names vs integers.
//             Next time, I would test and make sure each individual array works as I go, before trying both arrays at once.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {

    // Declare the realtor and houses arrays
    const int MAX_REALTORS = 25;
    string realtor[MAX_REALTORS];
    int houses[MAX_REALTORS];

    // declare other variables
    int numRealtors = 0;
    int numHouses = 0;
    int mostHousesSold;
    int topRealtorIndex;
    int leastHousesSold;
    int worstRealtorIndex;
    int i = 0;

    //open the Pgm5.txt file
    ifstream infile("Pgm5.txt");

    // check if file properly opened
    if (!infile.is_open()) { 
        cout << "File failed to open" << endl;
        return 1;
    }

    // process the file using a for loop
    while (!infile.eof()) {
        infile >> realtor[i];
        numRealtors++;
        infile >> houses[i];
        numHouses += houses[i];
        i++;
    }

    // check for negative numbers
    for (i = 0; i < numRealtors; ++i) {
        if (houses[i] < 0) {
            houses[i] = abs(houses[i]);
        }
    }

    // find the top realtor/houses sold
    mostHousesSold = houses[0];
    for (i = 0; i < numRealtors; i++) {
        if (houses[i] > mostHousesSold) {
            mostHousesSold = houses[i];
            topRealtorIndex = i;
        }
    }

    // find the worst realtor/houses sold
    leastHousesSold = houses[0];
    for (i = 0; i < numRealtors; i++) {
        if (houses[i] < leastHousesSold) {
            leastHousesSold = houses[i];
            worstRealtorIndex = i;
        }
    }

    //=========================== Output ==============================
    // header
    cout << endl;
    cout << endl;
    cout << "Realtor Competition Results" << endl;
    cout << "================================" << endl;

    // display each realtor and their houses sold
    for (i = 0; i < numRealtors; ++i) {
        cout << "Realtor " << setw(2) << i + 1 << " named " << realtor[i] << " sold " << houses[i] << " houses" << endl;
    }

    // display summary
    cout << endl;
    cout << "The winner is realtor " << topRealtorIndex + 1 << " named " << realtor[topRealtorIndex] << " by selling " << houses[topRealtorIndex] << " houses." << endl;
    cout << "Realtor " << worstRealtorIndex + 1 << " named " << realtor[worstRealtorIndex] << " sold the least number of houses: " << houses[worstRealtorIndex] << "." << endl;
    cout << "And in total all realtors sold " << numHouses << " houses" << endl;
    cout << endl;

    return 0;
}