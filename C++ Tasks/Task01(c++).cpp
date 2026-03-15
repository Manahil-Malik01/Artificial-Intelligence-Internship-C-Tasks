#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));
    
    char playAgain;

    cout << "============================" << endl;
    cout << "   DOUBLE DICE SIMULATOR    " << endl;
    cout << "============================" << endl;

    do {
        // Generate two random numbers between 1 and 6
        int die1 = (rand() % 6) + 1;
        int die2 = (rand() % 6) + 1;
        int total = die1 + die2;

        // Display results
        cout << "\n[ Die 1 ]: " << die1 << endl;
        cout << "[ Die 2 ]: " << die2 << endl;
        cout << "  TOTAL  : " << total << endl;

        // Check for "Doubles" just for fun
        if (die1 == die2) {
            cout << "  DOUBLES! Nice roll." << endl;
        }

        cout << "\nRoll again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for rolling! Goodbye." << endl;

    return 0;
}