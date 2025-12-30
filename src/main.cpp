#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get validated user choice
int getUserChoice()
{
    int choice;
    while (true)
    {
        cout << "Enter your choice (0-Rock, 1-Paper, 2-Scissors: ";
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 2)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
        }
        else
        {
            return choice;
        }
    }
}

// Function to generate computer choice
int getComputerChoice()
{
    return rand() % 3;
}

// Function to determine winner
// Return: 0 = Draw, 1 = User Wins, -1 = Computer Wins
int determineWinner(int user, int computer)
{
    if (user == computer)
        return 0;

    if ((user == 0 && computer == 2) ||
        (user == 1 && computer == 0) ||
        (user == 2 && computer == 1))
    {
        return 1;
    }
    return -1;
}

// Function to display scoreboard
void displayScore(int userScore, int computerScore, int drawCount)
{
    cout << "\n--- Scoreboard ---" << endl;
    cout << "You: " << userScore << endl;
    cout << "Computer: " << computerScore << endl;
    cout << "Draws: " << drawCount << endl;
}

int main()
{
    srand(time(0)); // Seed one

    int userScore = 0;
    int computerScore = 0;
    int drawCount = 0;
    char playAgain = 'y';

    string choices[] = {"Rock", "Paper", "Scissors"};

    while (playAgain == 'y' || playAgain == 'Y')
    {
        cout << "\n=== Rock Paper Scissors ===" << endl;

        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();

        cout << "\nYou chose: " << choices[userChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        int result = determineWinner(userChoice, computerChoice);

        if (result == 0)
        {
            cout << "Result: Draw!" << endl;
            drawCount++;
        }
        else if (result == 1)
        {
            cout << "Result: You Win!" << endl;
            userScore++;
        }
        else
        {
            cout << "Result: Computer Wins!" << endl;
            computerScore++;
        }

        displayScore(userScore, computerScore, drawCount);

        cout << "\nPlay again (y/n): ";
        cin >> playAgain;
    }
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