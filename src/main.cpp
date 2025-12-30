#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // Seed one

    int userChoice;
    char playAgain = 'y';

    int userScore = 0;
    int computerScore = 0;
    int drawCount = 0;

    string choices[] = {"Rock", "Paper", "Scissors"};

    while (playAgain == 'y' || playAgain == 'Y')
    {
        cout << "\n=== Rock Paper Scissors ===" << endl;
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

        // Decide winner & update scores
        if (userChoice == computerChoice)
        {
            cout << "Result: Draw!" << endl;
            drawCount++;
        }
        else if (
            (userChoice == 0 && computerChoice == 2) ||
            (userChoice == 1 && computerChoice == 0) ||
            (userChoice == 2 && computerChoice == 1))
        {
            cout << "Result: You Win!" << endl;
            userScore++;
        }
        else
        {
            cout << "Result: Computer Wins!" << endl;
            computerScore++;
        }

        // Display Scoreboard
        cout << "\n--- Scoreboard ---" << endl;
        cout << "You: " << userScore << endl;
        cout << "Computer: " << computerScore << endl;
        cout << "Draws: " << drawCount << endl;

        cout << "\nPlay again (y/n): ";
        cin >> playAgain;
    }
    cout << "\nFinal Score: " << endl;
    cout << "You: " << userScore << endl;
    cout << "Computer: " << computerScore << endl;
    cout << "Draws: " << drawCount << endl;
    cout << "\nThanks for playing!" << endl;

    return 0;
}