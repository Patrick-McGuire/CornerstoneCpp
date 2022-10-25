#include <iostream>
#include "ArduinoInterface.h"
#include <unistd.h> //for pauses/sleep

using namespace std;

/**
 * Waits for the user to enter a y before continuing
 * Blocking
 */
void waitToContinue() {
    string userLet;
    cout << "Enter y to continue" << endl;
    cin >> userLet;
    while (userLet != "y" && userLet != "Y") {
        cout << "Invalid Input. Please enter y to continue." << endl;
        cin >> userLet;
    }
}

void lower(string &lw) {
    for(char & i : lw) {
        i = (char)::tolower(i);
    }
}

/**
 * Wait for the user to enter a specific input before continuing
 * Blocking
 * @param desiredInput desired input
 */
void waitForInput(const string &desiredInput) {
    string inputStr;
    cout << "Please enter the answer." << endl;
    cin >> inputStr;
    lower(inputStr);
    if (inputStr == desiredInput) {
        cout << "Good Job!" << endl;
    }
    while (inputStr != desiredInput) {
        cout << "Wrong! Try again." << endl;
        cin >> inputStr;
    }
}

int main() {
    // Connect to the arduino
    Arduino arduino("COM35");
    // Reset the Arduino's state
    if (arduino.connected()) {
        arduino.write("$START\r\n");
    } else {
        std::cout << "Please connect the Arduino" << "\n";
        exit(0);
    }

    // Retrieve the users userName
    string userName;
    cout << "Please enter your name. Thank you and enjoy!" << endl;
    cin >> userName;

    // Puzzle game intro and instructions
    cout << "Hello " << userName << "! Welcome to NASA. The Colombia space shuttle is scheduled to launch later this week.\n"
                                      "You job is to figure out if it's ready to launch. This would be it's 28th time in space.\n"
                                      "To determine if it's ready, answer the following questions.\n"
                                      << endl;
    waitToContinue();

    cout << "Please complete the following fill in the blank questions! You may need to use google......" << endl;

    waitToContinue();

    //// Puzzle game
    // Question 1
    cout << "At night, you can see many _____. " << endl;
    waitForInput("stars");
    // Question 2
    cout << "Saturn's moon, _____, is bigger than Earth's moon. " << endl;
    waitForInput("titan");
    // Question 3
    cout << "Dr. Alan _____ is the principal investigator on New Horizons, the first-ever mission to Pluto." << endl;
    waitForInput("stern");
    // Question 4
    cout << "A _____-Neptunian object, is any minor planet in the Solar System that \n"
            "orbits the Sun at a greater average distance than Neptune" << endl;
    waitForInput("trans");

    // Final part of game
    cout << "Now look for your answers in the following word hunt. Be carefully, they may be backwards!\n"
            "If the shape created by the answers forms a square, then the shuttle is ready to launch.\n"
            "NATIT\n"
            "RRBER\n"
            "EWAKA\n"
            "TMUIN\n"
            "SRATS\n"
            "What shape do the answers form?" << endl;
    waitForInput("square");

    cout << "What was the teams decision on launching the Colombia Space Shuttle? Will they (yes) or not (no)?" << endl;
    waitForInput("yes");

    cout << "Thanks! We will be launching in a few days" << endl;
    sleep(1);
    cout << "A few days later...";


    cout << "Breaking News! If you look above at the Texas sky, you can see the Colombia Space Shuttle\n "
            "breaking into multiple pieces while re-entry. NASA is still trying to figure out what occurred, but\n"
            "something went terribly wrong." << endl;
    sleep(6); //waits 6 seconds
    cout << "The 7 astronauts on board have passed away" << endl;

    sleep(2);
    cout << "Your job is to figure out what went wrong." << endl;
    sleep(3);

    waitToContinue();

    cout << "We don't really have much to work of off yet, but we can start with the wing. The left\n"
            "wing has a missing piece. What could it be? This missing piece caused the explosion\n"
            "Use the pieces in the front of the space shuttle to figure out what caused the issue.\n"
            "Put the correct piece into the socket on the back of the wing" << endl;

    waitForInput(arduino, "$CONT2\r\n");

    cout << "Good job! You found the right piece. This is a heat plate! Losing heat tiles has \n"
            "been a big issue in NASA for many years, with 2,000 heat tiles being lost while on an airplane for Colombia,\n"
            "along with 15 tiles being lost during blast off for the shuttle alone." << endl;
    sleep(3);

    waitToContinue();

    cout << "The damaged heat tile caused the heat to flow inside the space shuttle. With the high velocity and heat, it\n"
            "caused the shuttle to break up, leaving only remains of the space shuttle. But what damaged the heat tile?\n" << endl;
    sleep(3);

    waitToContinue();

    cout << "You need to locate what piece hit the heat tile and caused it to damage it, eventually causing it to fall off. There is \n"
            "a loose object on the space shuttle that caused the damaged heat tile. Find that loose object and pull it."<< endl;
    sleep(3);

    std::cout << "Continue after you have found the loose object" << std::endl;
    waitToContinue();

    cout << "The loose object was a piece of insulating foam. This was the key reason why the entire shuttle \n"
            "broke down during re-entry. Even though they knew about problems similar to this, the Committee decide to launch the space shuttle. \n"
            " In this case, NASA found that the piece of foam has damaged the shuttle a day after the launch, but the Engineers \n"
            "came to the conclusion that the problem was not vital enough, and ignored it. NASA knew that there could be a chain reaction after \n"
            "if one tile got damaged. but proceeded anyway. This negligence cost 7 people's lives and shows how careful engineers have to be when dealing with human life." << endl;
    sleep(3);

    waitToContinue();

    cout << "Thank you for helping!" << endl;
    return (0);
}