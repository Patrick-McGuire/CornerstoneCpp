#include <iostream>

enum RpsOption : int {
    ROCK = 0,
    PAPER = 1,
    SCISSORS = 2,
};


void computeWinner(RpsOption comp, RpsOption player) {
    if(comp == player) {
        // Tie
        std::cout << "tie\n";
    } else if((comp > player && comp - player == 1) || (comp == ROCK && player == SCISSORS)) {
        // Computer win
        std::cout << "comp win\n";
    } else {
        std::cout << "you win\n";
    }
}

int main() {
    std::cout << "Welcome to rock paper scissors!" << std::endl;
    std::cout << "To play enter r, p, or s, to play rock, paper, or scissors respectively." << std::endl;
//    std::string userInput;
//    std::cin >> userInput;
//    std::cout << userInput << std::endl;

    auto computerSelection = RpsOption(rand() % 3);
    computerSelection = SCISSORS;
    RpsOption player = SCISSORS;
    computeWinner(computerSelection, player);

//    return 0;
}
