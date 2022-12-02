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
    for (char &i : lw) {
        i = (char) tolower(i);
    }
}

/**
 * Wait for the user to enter a specific input before continuing
 * Blocking
 * @param desiredInput desired input
 */
void waitForInput(const string &desiredInput, const string &hint) {
    string inputStr;
    cout << "Please enter the answer." << endl;
    cin >> inputStr;
    lower(inputStr);
    if (inputStr == desiredInput) {
        cout << "Good Job!" << endl;
        return;
    }
    if(hint != "none") {
        cout << "If you need a hint enter \"hint\"" << endl;
    }
    while (inputStr != desiredInput) {
        cout << "Wrong! Try again." << endl;
        skipWrong:
        cin >> inputStr;

        if(inputStr == "hint" && hint != "none") {
            cout << hint << endl;
            goto skipWrong;
        }

    }
}

void waitForInput(const string &desiredInput) {
    waitForInput(desiredInput, "none");
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

    // Puzzle game intro and instructions
    cout << "Hello! Welcome to NASA. The Colombia space shuttle is scheduled to launch later this week.\n"
            "You job is to figure out if it's ready to launch. This would be it's 28th time in space.\n"
            "To determine if it's ready, answer the following questions." << endl;
    waitToContinue();
    cout << "" << endl;

    cout << "Please complete the following multiple choice questions!" << endl;
    waitToContinue();
    cout << "" << endl;

    //// Puzzle game
    // Question 1
    cout << "At night, you can see many _____.\n" << endl;
    waitForInput("stars",  "It could be any of the following:\nmoons\n"
                       "voids\n"
                       "stars\n"
                       "gases");

    // Question 2
    cout << "Saturn's moon, _____, is bigger than Earth's moon.\n" << endl;
    waitForInput("titan", "It could be any of the following:\ntitan\n"
                      "thebe\n"
                      "ariel\n"
                      "naiad");

    // Question 3
    cout << "Dr. Alan _____ is the principal investigator on New Horizons, the first-ever mission to Pluto.\n" << endl;
    waitForInput("stern", "It could be any of the following:\nevans\n"
                          "olson\n"
                          "stone\n"
                          "stern" );

    // Question 4
    cout << "A _____-Neptunian object, is any minor planet in the Solar System that orbits the Sun at a greater average \n"
            "distance than Neptune.\n" << endl;
    waitForInput("trans", "It could be any of the following:\ntrans\n"
                          "orbit\n"
                          "array\n"
                          "close");

    // Final part of game
    cout << "" << endl;
    cout << "Now look for your answers in the following word hunt. Be carefully, they may be backwards!\n"
            "Find them and cross them out mentally.\n"
            "N A T I T\n"
            "R R B E R\n"
            "E W A K A\n"
            "T M U I N\n"
            "S R A T S" << endl;
    cout << "When you cross them out mentally, and the words will connect to make a shape! For example:\n"
            "S . . . .\n"
            "H M . . .\n"
            "A . A . .\n"
            "P . . R .\n"
            "E J E C T\n"
            "These words form a right triangle!" << endl;
    waitToContinue();
    cout << "" << endl;

    cout << "Here are the two possible shapes that can be formed. It will determine if it's ready or not!\n"
            "Square: ready to launch\n"
            "Hashtag: not ready to launch\n"
            "Now, with the words you found in the multiple choice, what shape does it form?" << endl;
    waitForInput("square");
    cout << "" << endl;

    cout << "What was the teams decision on launching the Colombia Space Shuttle? Will they (yes) or not (no)?" << endl;
    waitForInput("yes");
    cout << "" << endl;

    cout << "Thanks! We will be launching in a few days" << endl;
    sleep(1);

    cout << "A few days later..." << endl;
    sleep(2);

    cout << "Breaking News! If you look above at the Texas sky, you can see the Colombia Space Shuttle\n "
            "breaking into multiple pieces while re-entry. NASA is still trying to figure out what occurred, but\n"
            "something went terribly wrong." << endl;
    sleep(5); //waits 6 seconds

    cout << "The 7 astronauts on board have passed away" << endl;
    sleep(1);

    cout << "Your job is to figure out what went wrong!" << endl;
    sleep(2);
    waitToContinue();
    cout << "" << endl;

    cout << "We don't really have much to work of off yet, so let's just look around the shuttle. There are many missing holes\n"
            "around the shuttle! Why? One of these holes was the reason why everything else disintegrated.\n"
            "Use the pieces to find where (which hole) did the problem begin and what piece came loose.\n"
            "Put the correct piece in the right hole.\n"
            "Note: The First Task light will light up when stage is complete.\n"
            "Hint: You can move the space shuttle model to find the right hole!" << endl;

    waitForInput(arduino, "$CONT2\r\n");
    cout << "" << endl;

    cout << "Good job! You found the right piece. This is a heat plate! Losing heat tiles has \n"
            "been a big issue in NASA for many years, with 2,000 heat tiles being lost while on an airplane for Colombia,\n"
            "along with 15 tiles being lost during blast off for the shuttle alone." << endl;
    sleep(3);
    waitToContinue();
    cout << "" << endl;

    cout << "The damaged heat tile caused the heat to flow inside the space shuttle. With the high velocity and heat, it\n"
            "caused the shuttle to break up, leaving only remains of the space shuttle. But what damaged the heat tile?\n" << endl;
    sleep(3);
    waitToContinue();
    cout << "" << endl;

    cout << "You need to locate what piece hit the heat tile and caused it to damage it, eventually causing it to fall off. There is \n"
            "a loose object on the space shuttle that caused the damaged heat tile. Find that loose object and pull it." << endl;

//    std::cout << "Continue after you have found the loose object" << std::endl;
//    waitToContinue();
    waitForInput(arduino, "$CONT3\r\n");

    cout << "Good Job!\n"
            "\n"
            "The loose object was a piece of insulating foam. This was the key reason why the entire shuttle broke down \n"
            "during re-entry. Even though they knew about problems similar to this, the Committee decide to launch the space shuttle. \n"
            "In this case, NASA found that the piece of foam has damaged the shuttle a day after the launch, but the Engineers \n"
            "came to the conclusion that the problem was not vital enough, and ignored it. NASA knew that there could be a chain \n"
            "reaction after if one tile got damaged. but proceeded anyway. This negligence cost 7 people's lives and shows how \n"
            "careful engineers have to be when dealing with human life." << endl;
    sleep(3);
    waitToContinue();
    cout << "" << endl;

    cout << "Thank you for helping!" << endl;

    arduino.write("$END\r\n");

    return (0);
}