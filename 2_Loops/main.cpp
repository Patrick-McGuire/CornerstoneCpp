#include <iostream>

/**
 * Data type to track moves
 */
enum RpsOption : int {
    ROCK = 0,
    PAPER = 1,
    SCISSORS = 2,
};

/**
 * String constants to use in print statements
 */
const char *rpsOptionStr[] = {"rock", "paper", "scissors"};

/**
 * Computes the winner for a given set of moves, and print to the screen
 * @param comp computer's move
 * @param player player's move
 * @return if the game was not a tie
 */
bool computeWinner(RpsOption comp, RpsOption player) {
    if (comp == player) {
        // Tie
        std::cout << "You tied. Go again!" << std::endl;
        return false;
    } else if ((comp > player && comp - player == 1) || (comp == ROCK && player == SCISSORS)) {
        // Computer win
        std::cout << "The computer won :(" << std::endl;
    } else {
        // You won
        std::cout << "You won!" << std::endl;
    }
    return true;
}

/**
 * Asks the user for a input until they enter a valid input
 * @return their input
 */
RpsOption getInput() {
    std::cout << "Enter r, p, or s, to play rock, paper, or scissors respectively." << std::endl;
    while (true) {
        // Grab input
        std::string userInput;
        std::cin >> userInput;

        // Check if input is valid and return
        if(userInput.length() == 1 && (userInput[0] == 'r' || userInput[0] == 's' || userInput[0] == 'p')) {
            if(userInput[0] == 'r') {
                return ROCK;
            } else if(userInput[0] == 's') {
                return SCISSORS;
            } else if(userInput[0] == 'p') {
                return PAPER;
            }
        }

        // Let them know they FAILED
        std::cout << "Please re-enter r, p or s. Input must be a single, lower case letter!" << std::endl;
    }
}

int main() {



    // Seed the random number generator
    srand(time(nullptr));
    // Keep track of if the game has had a winner
    bool gameActive = true;

    // Game loop
    std::cout << "Welcome to rock paper scissors!" << std::endl;
    while (gameActive) {
        // Get the inputs
        auto playerSelection = getInput();
        auto computerSelection = RpsOption(rand() % 3);
        // Let the user know the computer input
        std::cout << "You chose " << rpsOptionStr[playerSelection] << " and the computer chose " << rpsOptionStr[computerSelection] << std::endl;
        // Compute and print the winner
        gameActive = !computeWinner(computerSelection, playerSelection);

        // Ask the user to play again
        if(!gameActive) {
            std::cout << "Play again? y to play again, anything else to quit.";
            std::string playAgain;
            std::cin >> playAgain;
            if (playAgain == "y") {
                gameActive = true;
            }
        }
    }
    // Done!
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
