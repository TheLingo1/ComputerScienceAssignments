/*
 Name: Compare Control Structures
 Date: 09-19-2022
 Author: Gabrieal Jimmy
 Purpose: This program is used to learn about comparison operators and how different types are compared
 */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int Int1, Int2;
    float Float1, Float2;
    string String1, String2;
    
    cout << "Please enter first integer number:  ";
    cin >> Int1;
    cout << endl;
    
    cout << "Please enter second integer number: ";
    cin >> Int2;
    cout << endl;

    if (Int1 != Int2){
        cout << "The greater integer is: " << (Int1 > Int2 ? Int1 : Int2) << endl;
    } else {
        cout << "Both integers are equal." << endl;
    }
    cout << endl << endl;
    
    cout << "Please enter first float number:  ";
    cin >> Float1;
    cout << endl;
    
    cout << "Please enter second float number: ";
    cin >> Float2;
    cout << endl;
    
    if (Float1 != Float2){
        cout << "The greater float is: " << (Float1 > Float2 ? Float1 : Float2) << endl;
    } else {
        cout << "Both floats are equal." << endl;
    }
    cout << endl << endl;
    
    cout << "Please enter first string (no spaces):  ";
    cin >> String1;
    cout << endl;
    
    cout << "Please enter second string (no spaces): ";
    cin >> String2;
    cout << endl;
    
    if (String1 != String2){
        cout << "The greater string is: " << (String1 > String2 ? String1 : String2) << endl;
    } else {
        cout << "Both strings are equal." << endl;
    }
    cout << endl << endl;
    
    cout << "Press the enter key once or twice to end..." << endl;
    cin.ignore(); cin.get();
    
    return EXIT_SUCCESS;
}
