#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Player Class
class Player
{
private:
    string name;
    int score;

public:
    Player(string playerName)
    {
        name = playerName;
        score = 0;
    }

    void incrementScore()
    {
        score++;
    }

    int getScore() const
    {
        return score;
    }

    string getName() const
    {
        return name;
    }
};

// Game Class
class Game
{
private:
    Player user;
    Player computer;
    int draws;
    string choices[3] = {"Rock", "Paper", "Scissors"};

public:
    Game() : user("You"), computer("Computer"), draws(0)
    {
        srand(time(0)); // Seed random number generator
    }

    int getUserChoice()
    {
        int choice;
        while (true)
        {
            cout << "\nEnter your choice: " << endl;
            cout << "0 - Rock" << endl;
            cout << "1 - Paper" << endl;
            cout << "2 - Scissors" << endl;
            cout << "Your choice: ";
            cin >> choice;

            if (cin.fail() || choice < 0 || choice > 2)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Try again." << endl;
            }
            else
            {
                return choice;
            }
        }
    }

    int getComputerChoice()
    {
        return rand() % 3;
    }

    void determineWinner(int userChoice, int computerChoice)
    {
        cout << "\nYou chose: " << choices[userChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        if (userChoice == computerChoice)
        {
            cout << "Result: Draw!" << endl;
            draws++;
        }
        else if (
            (userChoice == 0 && computerChoice == 2) ||
            (userChoice == 1 && computerChoice == 0) ||
            (userChoice == 2 && computerChoice == 1))
        {
            cout << "Result: You Win!" << endl;
            user.incrementScore();
        }
        else
        {
            cout << "Result: Computer Wins! " << endl;
            computer.incrementScore();
        }
    }

    void displayScoreboard() const
    {
        cout << "\n --- Scoreboard ---" << endl;
        cout << user.getName() << ": " << user.getScore() << endl;
        cout << computer.getName() << ": " << computer.getScore() << endl;
        cout << "Draws: " << draws << endl;
    }

    void play()
    {
        char playAgain = 'y';

        while (playAgain == 'y' || playAgain == 'Y')
        {
            int userChoice = getUserChoice();
            int computerChoice = getComputerChoice();

            determineWinner(userChoice, computerChoice);
            displayScoreboard();

            cout << "\nPlay again? (y/n): ";
            cin >> playAgain;
        }

        cout << "\nFinal Score: " << endl;
        displayScoreboard();
        cout << "\nTnaks for playing ";
    }
};

int main()
{
    Game game;
    game.play();
    return 0;
}