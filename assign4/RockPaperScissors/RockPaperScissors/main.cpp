/*
Program Name: Rock Paper Scissors
Author: Gabrieal Jimmy
Date: 10-03-2022
Module Purpose: Learn about loops and conditional statements
 */
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

    int selection, computerSelection;
    int ties = 0, wins = 0, losses = 0;
    


int main() {
    bool playAgain = true;
    do {
        cout << "Please choose a weapon from the menu below: " << endl;
        cout << "1 > Rock" << endl << "2 > Paper" << endl << "3 > Scissors" << endl << "4 > End Game" << endl << endl;
        cout << "Weapon Choice: ";
        cin >> selection;
        cout << endl << endl;
        bool reloop = false;
        switch (selection) {
            case 1:
                cout << "Player weapon is: Rock";
                break;
            case 2:
                cout << "Player weapon is: Paper";
                break;
            case 3:
                cout << "Player weapon is: Scissors";
                break;
            case 4:
                playAgain = false;
                reloop = true;
                break;
            default:
                cout << "Invalid menu choice, please try again" << endl << endl;
                reloop = true;
                break;
        }
        
        if (reloop){
            break;
        }
        cout << endl << endl;
        
        srand((int) time(NULL));
        computerSelection = (rand() % 3) + 1;
        
        switch (computerSelection) {
            case 1:
                cout << "Computer weapon is: Rock";
                break;
            case 2:
                cout << "Computer weapon is: Paper";
                break;
            case 3:
                cout << "Computer weapon is: Scissors";
                break;
            default:
                break;
        }
        cout << endl << endl;
        bool scissorsAndRock = false;
        if ((selection == 3 || selection == 1) && (computerSelection == 3 || computerSelection == 1)){
            scissorsAndRock = true;
        }
        if (selection == computerSelection){
            cout << "It's a tie";
            ties += 1;
        }
        else if (((selection > computerSelection) && !scissorsAndRock) || (selection == 1 && computerSelection == 3) ){
            cout << "You win!";
            wins += 1;
        } else {
            cout << "The computer wins!";
            losses += 1;
        }
        cout << endl << endl;
        
        cout << "Number of:" << endl;
        cout << setw(15) << left << "Ties" << ": " << ties << endl;
        cout << setw(15) << left << "Player Wins" << ": " << wins << endl;
        cout << setw(15) << left << "Computer Wins" << ": " << losses << endl;
        
        cout << "Press the enter key once or twice to continue ...";
        cin.ignore(); cin.get();

    } while (playAgain);
    
    return EXIT_SUCCESS;
}
