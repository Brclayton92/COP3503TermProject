//
// Created by Brock on 4/10/2018.
//

#ifndef COP3503TERMPROJECT_SUPERCHARACTER_H
#define COP3503TERMPROJECT_SUPERCHARACTER_H

#include "vector"
#include <iostream>
#include "string"
using namespace std;


class SuperCharacter {
private:
    string name; // stores characters name
    int certainty = 0; // tracks how many questions character has passed without being eliminated
    vector <bool> attributeArray; // vector that stores attributes in the same order as questions that correspond to each attribute

public:
    SuperCharacter(string superTextFile); //comments on methods can be found near their definitions in SuperCharacter.cpp
    string getName();
    vector<bool> getattributeArray();
    void increaseCertainty();

};


#endif //COP3503TERMPROJECT_SUPERCHARACTER_H
