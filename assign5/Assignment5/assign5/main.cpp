#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

bool isPrime(uint num){
    for(uint i = 2; i <= num/2; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    uint maxValue, primeCount = 0;
    ofstream file;
    file.open("PrimeOut.txt");
    do {
        cout << "Enter the max range value between 1 and 100 inclusive ";
        cin >> maxValue;
        if (maxValue >= 1 && maxValue <= 100){
            break;
        }
        cout << "Error: entered number is not within range 1 through 100 inclusive" << endl;
    } while (true);
    
    cout << "The primes that are <= " << maxValue << " are:";
    file << "The primes that are <= " << maxValue << " are:";
    
    for (uint j = 2; j <= maxValue; j++){
        if (isPrime(j)){
            if ( primeCount % 10 == 0){
                cout << endl;
                file << endl;
            }
            // If on a tenth number cout a new line first
            cout << setw(5) << j;
            file << setw(5) << j;
            primeCount++;
            
        }
    }
    cout << endl;
    return 0;
}
