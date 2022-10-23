/**
 * @file main.cpp
 * C++ quiz, by Patrick-McGuire
 * No partner
 * Outside reference used: https://cplusplus.com/reference/istream/istream/
 */


#include <iostream>
#include <cstdlib>

/**
 * Constants
 */
const char *computer = "The computer";
const char *player = "You";

/**
 * Gets a integer between 1 and 3 from the console
 * @param msg Message to print before asking for the input
 * @return Number input
 */
int getUserInput(const char *msg) {
    // Print the specified message
    std::cout << msg << ". ";
    int temp = 0;
    while (temp < 1 || temp > 3) {
        // Get the input
        std::cout << "Please enter a valid input (1, 2, or 3)" << std::endl;
        std::cin >> temp;
        // Robustness. This just allows the user to enter garbage and the program will be fine
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return temp;
}

/**
 * Generate a random number in the range specified
 * @param min bottom of range
 * @param max top of range
 * @return random number
 */
int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;      // Pseudo-random algorithm
}

bool run();

/**
 * Main game loop and code
 * @return exit code
 */
int main() {
    // Seed the pseudo-random number generator
    srand(time(nullptr));
    // Create the variables needed to track game progress
    int computerScore = 0, playerScore = 0, playerGuess = 0, playerMove = 0, computerGuess = 0, computerMove = 0;
    // Variable to track the winner
    const char *winner;
    // Main game loop
    while (true) {
        // Get the user's move
        playerMove = getUserInput("Enter your move");
        playerGuess = getUserInput("Guess the computer's number");
        // Get the computer's move
        computerMove = getRandomInt(1, 3);
        computerGuess = getRandomInt(1, 3);
        // Report the moves to the user
        std::cout << "You played " << playerMove << " and guessed " << playerGuess << ". ";
        std::cout << "The computer played " << computerMove << " and guessed " << computerGuess << std::endl;
        // Compute round winner
        if (computerGuess == playerMove && playerGuess == computerMove) {
            std::cout << "You were both right. No one gets any points :(" << std::endl;
        } else if (computerGuess == playerMove) {
            std::cout << "The computer won" << std::endl;
            computerScore += computerMove + playerMove;
        } else if (playerGuess == computerMove) {
            std::cout << "You won!!!!!!" << std::endl;
            playerScore += computerMove + playerMove;
        } else {
            std::cout << "You both lost" << std::endl;
        }
        // Print out the current score
        std::cout << "Your score: " << playerScore << ", computer score: " << computerScore << std::endl;

        // Check if the game is over

        if (computerScore >= 10) {
            winner = computer;
            break;
        } else if (playerScore >= 10) {
            winner = player;
            break;
        }
    }


    std::cout << winner << " won the game!" << std::endl;
    return 0;
}
