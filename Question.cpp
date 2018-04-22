//
// Created by Brock on 4/16/2018.
//
#include <iostream>
#include "Question.h"
#include <limits>


//simple method that returns value stored in Question's answer field.
bool Question::getAnswer() {
    return answer;
}

// constructor sets question field to string containing question
Question::Question(const string tempQuestion) {
    question = tempQuestion;
}

// method that asks question stored in question field
void Question::askQuestion() {
    while (true) { // loops until user inputs 1, 2, or 3.
        int userInput = 0; // stores user input
        cout << question << endl;
        cout << "(1) yes" << endl;
        cout << "(2) no" << endl;
        cout << "(3) don't know" << endl;


        cin >> userInput;

        // if statement ensures user input is of proper type
        if (cin.fail()) {
            cin.clear();
            std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

            // setting msSize to -1 triggers input validation message on next line,
            userInput = -1;
        }

        switch (userInput) {
            case 1:            // case 1 triggers if user answers yes, sets answer to true
                answer = true;
                return;
                break;

            case 2:           // case 2 triggers if user answers no, sets answer to false
                answer = false;
                return;
                break;

            case 3:          // case 3 triggers if user answers don't know, skips question
                alreadyAsked = true;
                return;
            default:        // default case triggers when user input is incorrect
                cout << "That is not a proper input, please enter 1, 2, or 3." << endl;
        }
    }

}

// take absolute value of numTrue and numFalse and stores it in true false ratio.
void Question::setTrueFalseRatio() {
    trueFalseRatio = abs(numTrue - numFalse);
}

// increases numTrue for every remaining Character whose corresponding attribute bool to the current question is true
void Question::increaseNumTrue() {
    numTrue++;
}

// increases numTrue for every remaining Character whose corresponding attribute bool to the current question is false
void Question::increaseNumFalse() {
    numFalse++;
}

//resets numTrue for next round
void Question::resetNumTrue() {
    numTrue = 0;
}

// resets numfalse for next round
void Question::resetNumFalse() {
    numFalse = 0;
}

//simple method, returns value stored in trueFalseRatio
int Question::getTrueFalseRatio() {
    return trueFalseRatio;
}

// simple method that sets alreadyAsked field to true
void Question::setAlreadyAskedTrue() {
    alreadyAsked = true;
}

// simple getter method that returns value stored in alreadyAsked variable
bool Question::getAlreadyAsked() {
    return alreadyAsked;
}
