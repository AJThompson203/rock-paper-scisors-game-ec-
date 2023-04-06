#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
class Date {
public:
  // System Date.
  Date() {
    // gets current time & converts to local time
    time_t now = time(0);
    tm *time = localtime(&now);
    day = time->tm_mday;
    month = time->tm_mon + 1;
    year = time->tm_year + 1900;
  }

  void Print() const { cout << year << "-" << month << "-" << day << endl; }

private:
  int day;
  int month;
  int year;
};

class Game {
public:
  void play();
  void displayResults();

private:
  int humanChoice;
  int computerChoice;
  int totalHands = 0;
  int humanWins = 0;
  int computerWins = 0;
  int highestWins = 0;
  int gameWinner;
  void determineWinner();
};

void Game::play() {
  // Initialize random number generator
  srand(time(0));

  do {
    // Display menu options
    cout << "Choose an option:" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "4. Exit" << endl;
    cout << "" << endl;

    // Get human player's choice
    cout << "Enter your choice: ";
    cin >> humanChoice;
// Sepcifcation 1 - Loop the game until the human player exits
    if (humanChoice == 4) {
      break; 
    }

    // Generate computer's choice
    computerChoice = rand() % 3 + 1;

    // Determine winner
    totalHands++;
    determineWinner();

  } while (true);
}

void Game::determineWinner() {
  if (humanChoice == computerChoice) {
    cout << "\n~~ Its A Tie! ~~" << endl;
    cout << "" << endl;
  } else if (humanChoice == 1 && computerChoice == 3 ||
             humanChoice == 2 && computerChoice == 1 ||
             humanChoice == 3 && computerChoice == 2) {
    cout << "\n** You Win! **" << endl;
    cout << "" << endl;
    // specification Count the number of times the computer and the human each won

    humanWins++;
  } else {
    cout << "\n-- Computer Wins! --" << endl;
    cout << "" << endl;
    computerWins++;
  }
}

void Game::displayResults() {
  // Display hands played and times human/computer won as wellas totall winning hands of the game winner
  if (humanWins > computerWins) {
    highestWins = humanWins;
    gameWinner = 1; // Human player wins
  } else if (computerWins > humanWins) {
    highestWins = computerWins;
    gameWinner = 2; // Computer wins
  } else {
    highestWins = humanWins; // Tie game
    gameWinner = 0;
  }

  // results displaued
  cout << "Total number of hands played: " << totalHands << endl;
  cout << "Number of times human won: " << humanWins << endl;
  cout << "Number of times computer won: " << computerWins << endl;
  cout << "Highest total of winning hands: " << highestWins << endl;

  if (gameWinner == 1) {
    cout << "Game winner: Human player" << endl;
    ;
  } else if (gameWinner == 2) {
    cout << "Game winner: Computer" << endl;
    ;
  } else {
    cout << "Game ended in a tie." << endl;
    ;
  }
}

void ProgramGreeting();
int main() {
  ProgramGreeting();
  Game game;
  game.play();
  game.displayResults();
  return 0;
}
void ProgramGreeting() {
  cout << R"(
___________               __     __________                             
\______   \ ____   ____ |  | __ \______   \_____  ______   ___________ 
 |       _//  _ \_/ ___\|  |/ /  |     ___/\__  \ \____ \_/ __ \_  __ \
 |    |   (  <_> )  \___|    <   |    |     / __ \|  |_> >  ___/|  | \/
 |____|_  /\____/ \___  >__|_ \  |____|    (____  /   __/ \___  >__|   
        \/            \/     \/                 \/|__|        \/       
  ___         _________      .__                                       
 / _ \_/\    /   _____/ ____ |__| ______ _________________  ______     
 \/ \___/    \_____  \_/ ___\|  |/  ___//  ___/  _ \_  __ \/  ___/     
             /        \  \___|  |\___ \ \___ (  <_> )  | \/\___ \      
            /_______  /\___  >__/____  >____  >____/|__|  /____  >     
                    \/     \/        \/     \/                 \/      
  )" << '\n';

  // Date Date;
  cout << "Current Date: ";
  Date Date;
  Date.Print();
  cout << "Made by: Anthony Thompson" << endl;
  cout << "Rock Paper Scisscors EC Assignemtn" << endl;
  cout << "Due date: May 18th 2023" << endl;
  cout << "" << endl;

  cout << "" << endl;
}

/*

___________               __     __________
\______   \ ____   ____ |  | __ \______   \_____  ______   ___________
 |       _//  _ \_/ ___\|  |/ /  |     ___/\__  \ \____ \_/ __ \_  __ \
 |    |   (  <_> )  \___|    <   |    |     / __ \|  |_> >  ___/|  | \/
 |____|_  /\____/ \___  >__|_ \  |____|    (____  /   __/ \___  >__|
        \/            \/     \/                 \/|__|        \/
  ___         _________      .__
 / _ \_/\    /   _____/ ____ |__| ______ _________________  ______
 \/ \___/    \_____  \_/ ___\|  |/  ___//  ___/  _ \_  __ \/  ___/
             /        \  \___|  |\___ \ \___ (  <_> )  | \/\___ \
            /_______  /\___  >__/____  >____  >____/|__|  /____  >
                    \/     \/        \/     \/                 \/

Current Date: 2023-4-6
Made by: Anthony Thompson
Rock Paper Scisscors EC Assignemtn
Due date: May 18th 2023


Choose an option:
1. Rock
2. Paper
3. Scissors
4. Exit

Enter your choice: 1

-- Computer Wins! --

Choose an option:
1. Rock
2. Paper
3. Scissors
4. Exit

Enter your choice: 2

-- Computer Wins! --

Choose an option:
1. Rock
2. Paper
3. Scissors
4. Exit

Enter your choice: 2

~~ Its A Tie! ~~

Choose an option:
1. Rock
2. Paper
3. Scissors
4. Exit

Enter your choice: 3

-- Computer Wins! --

Choose an option:
1. Rock
2. Paper
3. Scissors
4. Exit

Enter your choice: 3

** You Win! **

Choose an option:
1. Rock
2. Paper
3. Scissors
4. Exit

Enter your choice: 4
Total number of hands played: 5
Number of times human won: 1
Number of times computer won: 3
Highest total of winning hands: 3
Game winner: Computer
*/