/*
Module Name: ArraysSearch
Date Written: 11-30-2022
Author: Gabrieal Jimmy
Program Purpose: Learn about linear search algorithms and using arrays
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool searchList(int stdList[], uint numElems, int searchValue, uint &foundIndex){
    bool found = false;
    
    for (int i = 0; i < numElems; i++){
        if (stdList[i] == searchValue){
            foundIndex = i;
            found = true;
            break;
        }
    }
    
    return found;
}

void readFileToArray(string filePath, int *array, uint &arraySize) {
    int inInt, index;
    ifstream fileStream;
    fileStream.open(filePath);
    for (index = 0; fileStream >> inInt; index++){
        array[index] = inInt;
    }
    arraySize = index;
    fileStream.close();
}

int main() {
    int standardArray[100], testArray[50];
    uint stdArraySize, testArraySize, foundIndex;
    
    readFileToArray("LSStandard.txt", standardArray, stdArraySize);
    readFileToArray("LSTest.txt", testArray, testArraySize);
    
    for (int i = 0; i < testArraySize; i++){
        cout << "Number " << i + 1 << " (" << setw(3) << testArray[i] << ") ";
        if (searchList(standardArray, stdArraySize, testArray[i], foundIndex)){
            cout << "was located at index " << foundIndex << "." << endl;
        } else {
            cout << "was not in the file." << endl;
        }
    }

    
    return 0;
}
