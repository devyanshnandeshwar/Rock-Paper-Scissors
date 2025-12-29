#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // Seed one

    int userChoice;
    char playAgain = 'y';

    string choices[] = {"Rock", "Paper", "Scissors"};

    while (playAgain == 'y' || playAgain == 'Y')
    {
        cout << "=== Rock Paper Scissors ===" << endl;
        cout << "0 - Rock" << endl;
        cout << "1 - Paper" << endl;
        cout << "2 - Scissors" << endl;

        // Input validation
        while (true)
        {
            cout << "Enter your choice: ";
            cin >> userChoice;

            if (cin.fail() || userChoice < 0 || userChoice > 2)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter 0, 1, or 2." << endl;
            }
            else
            {
                break;
            }
        }

        int computerChoice = rand() % 3;

        cout << "\nYou chose: " << choices[userChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        // Decide winner
        if (userChoice == computerChoice)
        {
            cout << "Result: Draw!" << endl;
        }
        else if (
            (userChoice == 0 && computerChoice == 2) ||
            (userChoice == 1 && computerChoice == 0) ||
            (userChoice == 2 && computerChoice == 1))
        {
            cout << "Result: You Win!" << endl;
        }
        else
        {
            cout << "Result: Computer Wins!" << endl;
        }

        cout << "\nPlay again (y/n): ";
        cin >> playAgain;
    }
    cout << "\nThanks for playing!" << endl;
    return 0;
}