//
// Created by Brock on 4/16/2018.
//

#ifndef COP3503TERMPROJECT_QUESTION_H
#define COP3503TERMPROJECT_QUESTION_H

#include "string"
using namespace std;


class Question {
private:
    string question; // stores string of question
    bool answer;     //stores bool of answer
    int trueFalseRatio; // stores ratio of character whose response to this question is true or false
    int numTrue = 0;  // stores number of characters whose response to this question is true
    int numFalse = 0; //stores number of characters whose response to this question is false
    bool alreadyAsked = false; // used to determine whether the question has already been asked

public:
    //comments on methods can be found near their definitions in Question.cpp
    Question(string tempQuestion);
    bool getAnswer();
    void askQuestion();
    void setTrueFalseRatio();
    int getTrueFalseRatio();
    void increaseNumTrue();
    void increaseNumFalse();
    void resetNumTrue();
    void resetNumFalse();
    void setAlreadyAskedTrue();
    bool getAlreadyAsked();
};


#endif //COP3503TERMPROJECT_QUESTION_H
