#include <iostream>
using namespace std;
#include "Question.h"
#include <fstream>
#include"vector"
#include "SuperCharacter.h"

/*
 * Main methods start
 */

// method containing algorithm that chooses the best order of questions to find the desired character the fastest.
void questionSelection(vector <Question> questionVector, vector <SuperCharacter> superCharVector) {
    int i = 0; // variable that stores the index of the best question each round

    while (true) { // loops until return statement is reached when SuperCharVector.size()  == 1;
        for (int k = 0; k < questionVector.size(); k++){ // for loop that iterates through vector array of questions
            for (int l = 0; l < superCharVector.size(); l ++){ // nested for loop that iterates through each character

                /* The "attribute array" of each character and the "question array" are ordered such that questionArray[k]
                 * holds a question that corresponds to an attribute stored at attributeArray[k].*/

                /* the following if statements tallies the number of characters whose attribute at index k are true, and the number at index k that are false
                 * these values are stored in the fields "numTrue" and "numFalse" of questionArray[k].*/
                if (superCharVector[l].getattributeArray()[k] == true){
                    questionVector[k].increaseNumTrue();
                }

                if (superCharVector[l].getattributeArray()[k] == false){
                    questionVector[k].increaseNumFalse();
                }
            }
            //setTrueFalseRatio take the absolute value of the difference between numTrue and numFalse (abs(numTrue - numFalse)) and stores the result in the trueFalseRatio field.
            questionVector[k].setTrueFalseRatio();
            questionVector[k].resetNumFalse();
            questionVector[k].resetNumTrue();
        }

        int tempI = 0; // temp variable that stores the index of the current question with the lowest true false ratio
        int lowestTFratio = 10000; // stores the current lowest true false ratio to be compared to the TF ratio of the following questions. initialized with arbitrary large value.

        for (int k = 0; k < questionVector.size(); k++){ // loops through each question in questionVector
            /*compares the current question's true false ratio with
             * the lowest TF ratio encountered so far in the loop.
             * Also filters out questions that have already been asked using the
             * alreadyAsked field in questionVector[k].*/
            if (questionVector[k].getTrueFalseRatio() < lowestTFratio && questionVector[k].getAlreadyAsked() == false){
                lowestTFratio = questionVector[k].getTrueFalseRatio(); // updates lowest TF ratio if "if statement" is entered
                tempI = k; // updates temp index to index of current question if "if statement" is entered
            }
        }
        i = tempI; // after for loop is exited, updates index variable i to question with ultimately lowest TF ratio.

        questionVector[i].askQuestion();
        if (questionVector[i].getAlreadyAsked() == true) { //skips to the next question: triggered when user answers don't know.
            continue;
        }
        questionVector[i].setAlreadyAskedTrue();

        for (int j = 0; j < superCharVector.size(); j++){
            if (superCharVector[j].getattributeArray()[i] == questionVector[i].getAnswer()){
                superCharVector[j].increaseCertainty();
            }

            /*if (superCharVector[j].getCertainty() > 10) {
                cout << "Your character is " << superCharVector[j].getName() << ".";
                return;
            }*/

            if (superCharVector[j].getattributeArray()[i] != questionVector[i].getAnswer()) {
                superCharVector.erase(superCharVector.begin() + j);
                j--;
            }
        }

        if (superCharVector.size() == 1){
            cout << "Your character is " << superCharVector[0].getName() << ".";
            return;
        }


    }
}

/*
 * Main methods end
 */

int main() {
    vector <Question> questionVector;
    vector <SuperCharacter> superCharVector;

    /*SuperCharacter batman("Batman.txt");
    superCharVector.push_back(batman);

    SuperCharacter superman("Superman.txt");
    superCharVector.push_back(superman);

    SuperCharacter hela("Hela.txt");
    superCharVector.push_back(hela);*/

    /*
     * Receives character names from text file: start FIXME read comments
     */

    string tempStr;
    ifstream infile2("Character List.txt", ios::in); // test.text must be located in "C:\Users\Brock\CLionProjects\projectName\cmake-build-debug"

    if (infile2.is_open()){
        int counter = 1;
        while (getline(infile2, tempStr)) { // returns null when it reaches an empty line in the file
            SuperCharacter tempSuperChar(tempStr);
            superCharVector.push_back(tempSuperChar); //write file to a vector of strings
        }
        infile2.close();
    }

    else {
        cout << "no input file avilable";
    }

    /*
     * Receives character names from text file: end
     */


    /*
     *receives questions from external file: start FIXME read comments
     */

    string str;
    ifstream infile("Question List.txt", ios::in); // test.text must be located in "C:\Users\Brock\CLionProjects\projectName\cmake-build-debug"

    if (infile.is_open()){
        int counter = 1;
        while (getline(infile, str)) { // returns null when it reaches an empty line in the file
            Question tempQuestion(str, counter);
            questionVector.push_back(tempQuestion); //write file to a vector of strings
            counter++;
        }
        infile.close();
    }

    else {
        cout << "no input file avilable";
    }

    /*
     * receives questions from external file: end
     */


    /*
     * Question selector algorithm start
     */

    for (int i = 0; i < superCharVector.size(); i++){ // fixme: this is for testing purposes, delete later
        cout  << superCharVector[i].getName() << endl;
    }

     questionSelection(questionVector, superCharVector);

    /*
     * Question selector algoritm end
     */
    return 0;
}



