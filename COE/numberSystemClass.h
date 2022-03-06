#pragma once
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
        this->choiceCombination = ' ';
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

    cout << "\n[SELECT ACTION]\n"
    << "[1] Repeat from start\n"
    << "[2] Convert result to another number system\n"
    << "[3] Read the program info\n"
    << "[4] Exit program\n"
    << ">> ";
    cin >> userInput;
    cout << "\n________________________________________________________________________________________________\n";

    this->userAction = userInput;
}

void NumberSystem::setChoice() {
    int choice1, choice2;
    string numsys[] = {"Decimal", "Binary", "Octal", "Hexadecimal"};

    cout << "\n**NUMBER SYSTEMS CONVERTER**\n"
    << "Version 2.1.0 (Beta)\n"
    << "TABLE: \n";

    for (int i = 0; i <4; i++) {
        cout << "[" <<  i+1 << "] " << numsys[i] << endl;
    }

    cout << "\n[ENTER NUMBER OF CHOICE]\n"
    <<  "1. What number system would you like to convert?\n"
    << "From: "; 
    cin >> choice1;
    cout << "2. What number system would you like to convert into?\n"
    << "To: "; 
    cin >> choice2;

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