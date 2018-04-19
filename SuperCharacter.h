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
    string name;
    int certainty = 0;
    vector <bool> attributeArray;
    bool isGood;
    bool isMale;
    bool canFly;
    bool hasCape;
    bool isMarvel;
    bool hasPowers;
    bool isXMen;
    bool isAvenger;
    bool isGuardian;
    bool isJusticeLeague;
    bool hasMask;
    bool youngerThan25;
    bool wearsRed;
    bool wearsBlack;
    bool isRich;
    bool knowsMartialArts;
    bool isGenius;
    bool hasSuperStrength;
    bool isFromEarth;
    bool isAmerican;
    bool usesMagic;
    bool usesTech;
    bool hasSecretIdentity;

public:
    /*
     * getter methods Start
     */
    SuperCharacter();
    string getName();
    vector<bool> getattributeArray();
    int getCertainty();
    bool getIsGood();
    bool getIsMale();
    bool getCanFly();
    bool getHasCape();
    bool getIsMarvel();
    bool getHasPowers();
    bool getIsXMen();
    bool getisAvenger();
    bool getIsGuardian();
    bool getIsJusticeLeague();
    bool getHasMask();
    bool getYoungerThan25();
    bool getWearsRed();
    bool getHasSecretIdentity();
    bool getUsesTech();
    bool getUsesMagic();
    bool getIsAmerican();
    bool getIsFromEarth();
    bool getHasSuperStrength();
    bool getIsGenius();
    bool getKnowsMartialArts();
    bool getIsRich();
    bool getWearsBlack();
    /*
     * Getters methods end
     */
};


#endif //COP3503TERMPROJECT_SUPERCHARACTER_H
