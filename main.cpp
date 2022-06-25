#include <iostream>
#include <algorithm>
#include <cmath>
#include "numberSystemClass.h"
#include "exceptionHandling.h"
using namespace std;

void error();
void exit();
void programInfo();
void setValues(NumberSystem &);
void firstPhase(NumberSystem &);
void secondPhase(NumberSystem &);
long long int binary(long long int);
long long int octal(long long int);
string hexadecimal(long long int);
long long int binaryConversion(long long int);
long long int octalConversion(long long int);
long long int hexadecimalConversion(string);
void userAction(NumberSystem &);
void validateDecimalValue(string);
void validateBinaryValue(string);
void validateOctalValue(string);

int main() {
    char choice;
    bool onLoop = true;
    NumberSystem newNumberSystem;

    while (onLoop) {
        cout << "\n[SELECT ACTION]\n"
        << "[1] Proceed to the converter\n"
        << "[2] Read info\n"
        << ">> "; 
        cin >> choice;

        if (choice == '1' || choice == '2') {
            onLoop = false;
        }
        else {
            cout << "\n[INVALID CHOICE]\nPlease try again...\n";
        }
    }
    
    switch (choice) {
        case '2':
            programInfo();

        case '1':
            setValues(newNumberSystem);
            break;

        default:
            error();
    }
    return 0;
}

void setValues(NumberSystem &numberSystem) {
    long long int userIntInput;
    string userStringInput;
    bool onLoop = true;

    numberSystem.setChoice();

    switch(numberSystem.getChoiceCombination()) {
        case 1: case 4: case 27: case 256:
            while (onLoop) {
                try {
                    cout << "Enter Decimal value: ";
                    cin >> userStringInput;
                    validateDecimalValue(userStringInput);
                    userIntInput = stoi(userStringInput);
                    numberSystem.setIntValue(userIntInput);
                    onLoop = false;
                }
                catch (DecimalOverloading error) {
                    cout << "\n[NUMBER TOO BIG]\n"
                    << "Number you have entered: " << error.getDecimalError()
                    << "\nEnter a value not more than [520000]\n"
                    << "Please try again :}\n\n";
                }
                catch (IncorrectDecimal error) {
                    cout << "\n[NUMBER IS NOT A DECIMAL VALUE]\n"
                    << "Number you have entered: " << error.getDecimalError()
                    << "\nPlease try again :}\n\n";
                }
            }
            break;

        case 2: case 8: case 54: case 512:
            while (onLoop) {
                try {
                    cout << "Enter Binary value: ";
                    cin >> userStringInput;
                    validateBinaryValue(userStringInput);
                    userIntInput = stoi(userStringInput);
                    numberSystem.setIntValue(userIntInput);
                    onLoop = false;
                }
                catch (BinaryOverloading error) {
                    cout << "\n[NUMBER TOO BIG]\n"
                    << "You have entered a value which has more than the maximum threshold [19]\n"
                    << "Number of digits you have entered: " << error.getBinaryError()
                    << "\nPlease try again :}\n\n";
                }
                catch (IncorrectBinary error) {
                    cout << "\n[NUMBER IS NOT A BINARY VALUE]\n"
                    << "Number you have entered: " << error.getBinaryError()
                    << "\nPlease try again :}\n\n";
                }
            }
            break;

        case 3: case 12: case 81: case 768:
            while (onLoop) {
                try {
                    cout << "Enter Octal Value: ";
                    cin >> userStringInput;
                    validateOctalValue(userStringInput);
                    userIntInput = stoi(userStringInput);
                    numberSystem.setIntValue(userIntInput);
                    onLoop = false;
                }
                catch (OctalOverloading error) {
                    cout << "\n[NUMBER TOO BIG]\n"
                    << "You have entered a value which has more than the maximum threshold [6]\n"
                    << "Number of digits you have entered: " << error.getOctalError()
                    << "\nPlease try again :}\n\n";
                }
                catch (IncorrectOctal error) {
                    cout << "\n[NUMBER IS NOT AN OCTAL VALUE]\n"
                    << "Number you have entered: " << error.getOctalError()
                    << "\nPlease try again :}\n\n";
                }
            }
            break;

        case 1024: case 523: case 16: case 108:
            cout << "Enter Hexadecimal Value: ";
            cin >> userStringInput;
            numberSystem.setStringValue(userStringInput);
            break;

        default:
            error();
    }
    firstPhase(numberSystem);
}

void firstPhase(NumberSystem &numberSystem) {
    long long int intValue, result;
    string stringValue, stringResult;

    intValue = numberSystem.getIntValue();
    stringValue = numberSystem.getStringValue();

    switch(numberSystem.getChoiceCombination()) {
        case 1:
            cout << "\n>> The Decimal value for " << intValue << " is " << intValue << endl;
            numberSystem.setIntResult(intValue);
            break;

        case 4:
            result = binary(intValue);
            cout << "\n>> The Binary value for the Decimal [" << intValue << "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 27:
            result = octal(intValue);
            cout << "\n>> The Octal value for the Decimal[" << intValue << "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 256:
            stringResult = hexadecimal(intValue);
            cout << "\n>> The Hexadecimal value of the Decimal[" << intValue << "] is " << stringResult << endl;
            numberSystem.setStringResult(stringResult);
            break;

        case 2:
            result = binaryConversion(intValue);
            cout << "\n>> The Decimal Value of the Binary [" << intValue << "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 8:
            cout << "\n>> The Binary Value of the Binary [" << intValue << "] is " << intValue << endl;
            numberSystem.setIntResult(intValue);
            break;

        case 54:
            result = octal(binaryConversion(intValue));
            cout << "\n>> The Octal Value of the Binary [" << intValue << "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 3:
            result = octalConversion(intValue);
            cout << "\n>> The Decimal Value of the Octal [" << intValue << "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 12:
            result = binary(octalConversion(intValue));
            cout << "\n>> The Binary Value of the Octal [" << intValue << "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 81:
            cout << "\n>> The Octal Value of the Octal [" << intValue << "] is " << intValue << endl;
            numberSystem.setIntResult(intValue);
            break;

        case 512:
            stringResult = hexadecimal(binaryConversion(intValue));
            cout << "\n>> The Hexadecimal Value of the Binary [" << intValue << "] is " << stringResult << endl;
            numberSystem.setStringResult(stringResult);
            break;

        case 768:
            stringResult = hexadecimal(octalConversion(intValue));
            cout << "\n>> The Hexadecimal Value of the Octal [" << intValue << "] is " << stringResult << endl;
            numberSystem.setStringResult(stringResult);
            break;

        case 1024:
            cout << "\n>> The Hexadecimal Value of the Hexadecimal [" << stringValue << "] is " << stringValue << endl;
            numberSystem.setStringResult(stringValue);
            break;

        case 523:
            result = hexadecimalConversion(stringValue);
            cout << "\n>> The Decimal Value of the Hexadecimal [" << stringValue << "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 16:
            result = binary(hexadecimalConversion(stringValue));
            cout << "\n>> The Binary Value of the Hexadecimal [" << stringValue <<  "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        case 108:
            result = octal(hexadecimalConversion(stringValue));
            cout << "\n>> The Octal Value of the Hexadecimal [" << stringValue <<  "] is " << result << endl;
            numberSystem.setIntResult(result);
            break;

        default:
            error();
    }
    userAction(numberSystem);
}

void secondPhase(NumberSystem &numberSystem) {
    int c2;
    bool onLoop = true;
    string intToString;
    string numsys[] = {"Decimal", "Binary", "Octal", "Hexadecimal"};

    cout << endl;

    while (onLoop) {
        try {
            for (int i = 0; i <4; i++) {
                cout << "[" <<  i+1 << "] " << numsys[i] << endl;
            }
            cout << "\nWhat number system would you like to convert into?\n"
            << ">> ";
            cin >> intToString;
            numberSystem.validateUserAction(intToString);
            c2 = stoi(intToString);
            onLoop = false;
        }
        catch (InvalidAction error) {
            cout << "\n[INVALID ACTION]\n"
            << "Choice you inputed: " << error.getInvalidAction()
            << "\n\nPlease try again...\n";
        }
    }
    numberSystem.choices(numberSystem.getSecondChoice(), c2);
    numberSystem.setSecondChoice(c2);
    numberSystem.setIntValue(numberSystem.getIntResult());
    numberSystem.setStringValue(numberSystem.getStringResult());
    
    firstPhase(numberSystem);
}

void userAction(NumberSystem &numberSystem) {
    numberSystem.selectAction();

    switch(numberSystem.getUserAction()) {
        case '1':
            setValues(numberSystem);
            break;

        case '2':
            secondPhase(numberSystem);
            break;

        case '3':
            programInfo();
            setValues(numberSystem);
            break;

        case '4':
            exit();
            break;

        default:
            error();
    }
}

long long int binary (long long int num) {                                          //decimal to binary
    long long int numClone = num, reiteration =0, bin = 0, temp =1;

    while (numClone != 0){
        numClone /= 2;
        reiteration++;
    }
    int* array = new int[reiteration];

    for (int i = 0; i <reiteration; i++) {
        array[i] = num % 2;
        num = num / 2;
    }

    for (int i = 0; i <reiteration; i++) {
        bin = bin + (array[i] * temp);
        temp = temp * 10;
    }
    return bin;
}

long long int octal (long long int num){                                           //decimal to octal
    long long int numClone = num, mult = 1, rem = 0;

    while (numClone != 0){
        rem = rem + ((numClone % 8 ) * mult);
        numClone /= 8;
        mult *= 10;
    }
    return rem;
}

string hexadecimal (long long int num) {                           //decimal to hexadecimal
    long long int hde = num, hde1 = num, q, hdr, hdcounter =0;
    string HEXA;

    do {
        hde = hde / 16;
        hdcounter++;
    } while (hde != 0);

    long long int hdcontainer[hdcounter];

    for (int i = 0; i < hdcounter; i++){
        hdr = hde1 % 16;
        hde1 = hde1 /16;
        hdcontainer[i] = hdr;
    }

    string HDList[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    for (int i = 0; i <hdcounter; i++) {
        HEXA += HDList[hdcontainer[i]];
   }
   reverse(HEXA.begin(), HEXA.end());
   return HEXA;
}

long long int binaryConversion (long long int num){                            //binary to decimal
    long long int DEC = 0, REM = 0, j = 0;

    while (num != 0){
        REM = num % 10;
        num /= 10;
        DEC += REM * pow (2, j);
        j++;
    }
    return DEC;
}

long long int octalConversion(long long int num){                            //octal to decimal
    long long int deci = 0, i = 0, rem;

    while (num != 0){
    rem = num % 10;
    deci = deci + (rem* pow(8, i));
    i++;
    num = num / 10;
}
   return deci;
}

long long int hexadecimalConversion(string numString){                  //hexadecimal to decimal
    int len = numString.length();
    int base = 1;
    long long int res = 0;
    for (int i=len-1; i>=0; i--){
         if (numString[i]>='0' && numString[i]<='9'){
         res += (numString[i] - 48)*base;
         base = base * 16;
      }
      else if (numString[i]>='A' && numString[i]<='F'){
         res += (numString[i] - 55)*base;
         base = base*16;
      }
   }
   return res;
}

void error (){                                       //function is called when user chooses an invalid option
    cout << "\n[ERROR] INVALID INPUT\n"
    << "Reloading...\n";
}

void programInfo (){                          //a void function to display the information of the program
    char choice;
    
    cout << "\n[1] INFO:\n"
    << "    Developer name:\tJann Louie Q. Almirante\n"
    << "    Course:\t\tComputer Engineering I\n"
    << "    Subject:\t\tCOE 131 | PROGRAMMING LOGIC AND DESIGN\n"
    << "    Professor:\t\tEng. Don Opada\n"
    << "    University:\t\tNegros Oriental State University (NORSU)\n"
    << "\n[2] PPROGRAM CONSISTS OF:\n"
    << "    (a) CONDITIONAL OPERATORS\n"
    << "    (b) ARRAYS\n"
    << "    (c) LOOPS\n"
    << "    (d) FUNCTIONS\n"
    << "    (e) POINTERS\n"
    << "\n[3] CONVERTER INFO:\n"
    << "    - A program that converts any number system to another number system\n"
    << "    - Input a number that is not too big for program to work flawlessly\n"
    << "    - More instructions are stated within the program\n"
    << "\nFor more info and if you want to learn how the program works, please read the manual :>\n"
    << "\nRest assured that the program works accurately if program does not encounter any problems\n"
    << "\nThank you for your time!\n"
    << "\nPRESS [1] TO START THE CONVERTER\n"
    << "PRESS [2] TO EXIT PROGRAM\n"
    << ">> ";
    cin >> choice;
    cout << "________________________________________________________________________________________________\n";

    switch (choice){
        case '1':
            cout << "\nEntering program...\n";
            break;

        case '2':
            exit(); 
            break;

        default:
            error();
            programInfo();
    }
}

void exit (){                                       //function is called when the user wants to exit the program
    cout << "\n[END OF PROGRAM] Thank you for your patronage :>\n"; 
}

void validateDecimalValue(string value) {
    bool allAreDigits = true;

    for (int i = 0; i < value.size(); i++) {
        if (!isdigit(value[i])) {
            allAreDigits = false;
        }
    }

    if (!allAreDigits) {
        throw IncorrectDecimal(value);
    }

    int stringToInt = stoi(value);

    if (stringToInt > 520000) {
        throw DecimalOverloading(stringToInt);
    }
}

void validateBinaryValue(string value) {
    bool allDigitsAreValid = true;
    int size = value.size();

    for (int i = 0; i < size; i++) {
        if (value[i] != '1' && value[i] != '0') {
            allDigitsAreValid = false;
        }
    }

    if (!allDigitsAreValid) {
        throw IncorrectBinary(value);
    }

    if (size > 19) {
        throw BinaryOverloading(size);
    }
}

void validateOctalValue(string value) {
    bool allDigitsAreValid = true;
    int size = value.size(), tempInt;
    string tempChar;

    for (int i = 0; i < size; i++) {
        if (!isdigit(value[i])) {
            allDigitsAreValid = false;
        }
    }

    if (!allDigitsAreValid) {
        throw IncorrectOctal(value);
    }

    for (int i = 0; i < size; i++) {
        tempChar = value[i];
        tempInt = stoi(tempChar);

        if (tempInt > 7 || tempInt < 0) {
            allDigitsAreValid = false;
        }
    }

    if (!allDigitsAreValid) {
        throw IncorrectOctal(value);
    }

    if (size > 6) {
        throw OctalOverloading(size);
    }
}