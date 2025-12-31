#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Player Class
// Respreseents a participant in the game (User or Computer)
class Player
{
private:
    string name;
    int score;

public:
    Player(string playerName) : name(playerName), score(0) {}

    void incrementScore()
    {
        score++;
    }

    void resetScore()
    {
        score = 0;
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

    void showMenu() const
    {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Play Game" << endl;
        cout << "2. View Scoreboard" << endl;
        cout << "3. Reset Scoreboard" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
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

    void playRound()
    {
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();

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

    void resetScoreboard()
    {
        user.resetScore();
        computer.resetScore();
        draws = 0;
        cout << "\nScoreboard reset successfully!" << endl;
    }

    void start()
    {
        int option;

        while (true)
        {
            showMenu();
            cin >> option;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Try again." << endl;
                continue;
            }

            switch (option)
            {
            case 1:
                playRound();
                break;
            case 2:
                displayScoreboard();
                break;
            case 3:
                resetScoreboard();
                break;
            case 4:
                cout << "Exiting the game. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid option. Please try again. Choose 1-4." << endl;
            }
        }
    }
};

int main()
{
    Game game;
    game.start();
    return 0;
}