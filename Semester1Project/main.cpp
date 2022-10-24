#include <iostream>
#include "ArduinoInterface.h"
#include <unistd.h> //for pauses/sleep

using namespace std;

/**
 * Waits for the user to enter a y before continuing
 * Blocking
 */
void waitToContinue() {
    char userLet;
    cout << "Enter y to continue" << endl;
    cin >> userLet;
    while (userLet != 'y') {
        cout << "Invalid Input. Please enter y to continue." << endl;
        cin >> userLet;
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
//        exit(0);
    }

    // Retrieve the users userName
    string userName;
    cout << "Please enter your name. Thank you and enjoy!" << endl;
    cin >> userName;

    // Puzzle game intro and instructions
    cout << "Hello " << userName << "! Welcome to NASA. Your boss is asking you to submit the Executive Committee's response of launching\n"
                                      "the Colombia Space Shuttle for it's 28th time after it's regular evaluation. With this word hunt,\n"
                                      "find the shape the words will make (it can be either a square or a hashtag) in order to get\n"
                                      "the log in information and to find their decision. Please submit it as soon as you can!" << endl;
    waitToContinue();

    cout << "A series of fill in the blanks will be asked. Use the answers to find the words in the word hunt and see what\n"
            "shape is shown! It will increase in difficulty, so good luck!" << endl;

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
    cout << "A _____-Neptunian object, also written transneptunian object, is any minor planet in the Solar System that \n"
            "orbits the Sun at a greater average distance than Neptune" << endl;
    waitForInput("trans");

    // Final part of game
    cout << "You have correctly found all of the words! Now, what shape does it form in this word hunt?\n"
            "Here is the word hunt:\n"
            "NATIT\n"
            "ORBER\n"
            "VEAKA\n"
            "AMUTN\n"
            "SRATS\n"
            "Does it form a square or a hashtag?" << endl;
    waitForInput("square");

    // i can make it so it goes back to the top if they get it wrong once
    cout << "Great! This was the teams decision.\n"
            "The team has decided to launch the Colombia Space Shuttle for January 16, 2003." << endl;

    waitToContinue();

    string decision;
    cout << "What was the teams decision on launching the Colombia Space Shuttle? Will they (yes) or not (no)?" << endl;
    cin >> decision;
    if (decision == "yes") {
        cout << "That is correct. Thank you for your help." << endl;
    } else if (decision == "no") {
        cout << "That is incorrect. Read back on the decision." << endl;
        cin >> decision;
    } else {
        cout << "Invalid Input. Enter 'yes' or 'no'." << endl;
        cin >> decision;
    }

    cout << "A few days later";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << "." << endl;
    sleep(1);

    //Arduino arduino("COM10");

    cout << "News Reporter A: Breaking News! If you look above at the Texas sky, you can see the Colombia Space Shuttle\n "
            "breaking into multiple pieces while re-entry. NASA is still trying to figure out what occurred, but it \n"
            "seems to me that something went terribly wrong." << endl;
    sleep(6); //waits 6 seconds
    cout << "News Reporter B: We just received news that the 7 astronauts on board have passed away. This is a serious \n"
            "problem we have here." << endl;
    sleep(4);
    cout << "News Reporter A: Come back for more news coverage on this horrible disaster here on-" << endl;
    sleep(3);
    cout << "*TV is shut off*" << endl;
    sleep(2);
    cout << "What is going on? As an engineer, you need to figure out what went wrong!" << endl;
    sleep(3);

    waitToContinue();

    cout << "Great! Well, not so great. We don't really have much to work of off, but we can start here. Look at the\n"
            "piece of wood with a missing piece. It seems that this is the main cause for the whole break up of the \n"
            "shuttle. What could it be? Try to find the missing piece that fits into the hole. " << endl;

//    waitForInput(arduino, "$CONT2\r\n");

    cout << "Good job! You found the right piece. What do you think it is? This is a heat plate! It looks\n"
            " like its damaged too... " << endl;
    sleep(3);

    waitToContinue();

    cout << "Here, we can see that the heat tile was damaged, causing for the heat to flow inside\n"
            "the space shuttle. This heat tile was located on the left wing of the shuttle. With the high velocity and heat,\n"
            "it caused the shuttle to break up, leaving only remains of the space shuttle such as this heat tile. \n"
            "Now, we need to find what caused this heat tile to break." << endl;
    sleep(3);

    waitToContinue();

    cout << "Move to the space shuttle itself now. We need to locate what piece hit the heat tile and caused it to fall\n"
            "off. Here are multiple pieces of junk that are possible choices for it to hit the heat tile, and cause the\n"
            "disaster. Try pulling each one and find the one that broke the shape shuttle. " << endl;
    sleep(3);

    waitToContinue();

    cout << "Woah! This is the piece of thing that caused the entire thing to break. This piece of foam was the key reason\n"
            "as to why the entire shuttle broke down during re-entry. Even though the Committee decide to launch the space shuttle\n"
            "they knew about this problem even before-hand. Serious consequences were faced from those who allowed this\n"
            "disaster to occur." << endl;
    sleep(3);

    waitToContinue();

    cout << "Thank you for helping!" << endl;
    return (0);
}