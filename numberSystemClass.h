#pragma once
#include "exceptionHandling.h"
using namespace std;

class NumberSystem {
private:
    long long int intResult, intValue;
    int choiceCombination, secondChoice;
    char userAction;
    string stringResult, stringValue;

public:
    NumberSystem() {
        this->intResult = 0;
        this->stringResult = " ";
        this->choiceCombination = 0;
    }

    void choices(int, int);
    int getChoiceCombination();
    void setChoice();
    void setIntResult(long long int);
    void setStringResult(string);
    long long int getIntResult();
    string getStringResult();
    void setIntValue(long long int);
    long long int getIntValue();
    void setStringValue(string);
    string getStringValue();
    void selectAction();
    char getUserAction();
    void setSecondChoice(int);
    int getSecondChoice() const;
    void validateChoices(string, string);
    void validateUserAction(char);
    void validateUserAction(string);
};

void NumberSystem::setSecondChoice(int c2) {
    this->secondChoice = c2;
}

int NumberSystem::getSecondChoice() const {
    return this->secondChoice;
}

long long int NumberSystem::getIntResult() {
    return this->intResult;
}

string NumberSystem::getStringResult() {
    return this->stringResult;
}

void NumberSystem::setIntResult(long long int val) {
    this->intResult = val;
}

void NumberSystem::setStringResult(string val) {
    this->stringResult = val;
}

void NumberSystem::setIntValue(long long int val) {
    this->intValue = val;
}

long long NumberSystem::getIntValue() {
    return this->intValue;
}

void NumberSystem::setStringValue(string val) {
    this->stringValue = val;
}

string NumberSystem::getStringValue() {
    return this->stringValue;
}

void NumberSystem::selectAction() {
    char userInput;
    bool onLoop = true;

    while (onLoop) {
        try {
            cout << "\n[SELECT ACTION]\n"
            << "[1] Repeat from start\n"
            << "[2] Convert result to another number system\n"
            << "[3] Read the program info\n"
            << "[4] Exit program\n"
            << ">> ";
            cin >> userInput;
            validateUserAction(userInput);
            onLoop = false;
        }
        catch (InvalidAction error) {
            cout << "\n[INVALID ACTION]\n"
            << "Choice you inputed: " << error.getInvalidChoice()
            << "\n\nPlease try again...\n";
        }
    }
    cout << "\n________________________________________________________________________________________________\n";

    this->userAction = userInput;
}

void NumberSystem::setChoice() {
    bool onLoop = true;
    int choice1, choice2;
    string tempChoice1, tempChoice2;
    string numsys[] = {"Decimal", "Binary", "Octal", "Hexadecimal"};

    cout << "\n**NUMBER SYSTEMS CONVERTER**\n"
    << "Version 3.0.0 Alpha\n"
    << "TABLE: \n";

    for (int i = 0; i <4; i++) {
        cout << "[" <<  i+1 << "] " << numsys[i] << endl;
    }

    while (onLoop) {
        try {
            cout << "\n[ENTER NUMBER OF CHOICE]\n"
            <<  "1. What number system would you like to convert?\n"
            << "From: "; 
            cin >> tempChoice1;
            cout << "2. What number system would you like to convert into?\n"
            << "To: "; 
            cin >> tempChoice2;
            validateChoices(tempChoice1, tempChoice2);
            choice1 = stoi(tempChoice1);
            choice2 = stoi(tempChoice2);
            onLoop = false;
        }
        catch (InvalidAction error) {
            cout << "\n[CHOICES ARE NOT VALID]\n"
            << "Choices you have inputed:\n"
            << "Choice 1: " << error.getInvalidChoice1()
            << "\nChoice 2: " << error.getInvalidChoice2()
            << "\n\nPlease try again...\n";
        }
    }
    this->secondChoice = choice2;
    choices(choice1, choice2);
}

void NumberSystem::choices(int c1, int c2){                              //equation for switch statement in numSysDisplayInput
    if (c1 == 4 && c2 == 1){
        c1 = 523;
    } 
    else {
        for (int i=0; i<c2; i++){
            c1 = c1 * c2;
        }
    }
    this->choiceCombination = c1;
}

int NumberSystem::getChoiceCombination() {
    return choiceCombination;
}

char NumberSystem::getUserAction() {
    return this->userAction;
}

void NumberSystem::validateChoices(string c1, string c2) {
    char choiceDictionary[] = { '1', '2', '3', '4'};
    bool choice1IsValid = false, choice2IsValid = false;
    char tempChar1 = c1[0], tempChar2 = c2[0];

    for (int i=0; i<4; i++) {
        if (tempChar1 == choiceDictionary[i]) {
            choice1IsValid = true;
        }
        if (tempChar2 == choiceDictionary[i]) {
            choice2IsValid = true;
        }
    }

    if (!choice1IsValid || !choice2IsValid) {
        throw InvalidAction(c1, c2);
    }
}

void NumberSystem::validateUserAction(char action) {
    bool actionIsValid = false;
    char choiceDictionary[] = { '1', '2', '3', '4'};
    
    for (int i = 0; i <4; i++) {
        if (action == choiceDictionary[i]) {
            actionIsValid = true;
        }
    }
    
    if (!actionIsValid) {
        throw InvalidAction(action);
    }
}

void NumberSystem::validateUserAction(string stringAction) {
    bool actionIsValid = false;
    char action = stringAction[0];
    char choiceDictionary[] = { '1', '2', '3', '4'};
    
    for (int i = 0; i <4; i++) {
        if (action == choiceDictionary[i]) {
            actionIsValid = true;
        }
    }
    
    if (!actionIsValid) {
        throw InvalidAction(stringAction);
    }
}