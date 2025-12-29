#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int userChoice;

    cout << "=== Rock Paper Scissors ===" << endl;
    cout << "Enter your choice: ";
    cout << "0 - Rock" << endl;
    cout << "1 - Paper" << endl;
    cout << "2 - Scissors" << endl;
    cout << "Choices: ";
    cin >> userChoice;

    // Seed randon number generator
    srand(time(0));
    int computerChoice = rand() % 3;

    string choices[] = {"Rock", "Paper", "Scissors"};

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

    return 0;
}