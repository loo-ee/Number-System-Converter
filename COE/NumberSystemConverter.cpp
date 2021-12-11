#include <iostream>
#include <string>                                                   //libraries which the program needs
#include <string.h>
#include <sstream>
#include <cmath>
#include <algorithm>

void programDisclaimer();
void numSys();
int choices(int num, int num1);
int numSysDisplayInput(int forSwitch);
void numSysIntro();                                                //declaration of functions
int binary(int num);
int octal (int num);
std::string hexadecimal (int num);
void repeat(int num, int num1);
int cont(int num, int num1);
void numSysSecondPhase (int num, int bin, int num1);
int binConversion(int num);
int octConversion(int num);
int hexConversion(std::string numS);
void error();
void exit();

int main(){                                                      //main function
    char choice;                                                //user chooses DECIMAL CALCULATOR or NUMBER SYSTEM CONVERTER
    std::cout << std::endl 
    << "[SELECT ACTION]" << std::endl
    << "[1] Proceed to the converter" << std::endl
    << "[2] Read info" << std::endl
    << ">> "; std::cin >> choice;

    switch (choice) {
        case '1':
            numSys(); break;

        case '2':
            programDisclaimer(); break;

        default:
            error();
            main();
    }
    return 0;
}

void numSys (void) {                                           //first conversion
    int choice1, choice2;
    numSysIntro();
    std::cout << std::endl 
    << "[ENTER NUMBER OF CHOICE]" << std::endl
    <<  "1. What number system would you like to convert? " << std::endl
    << "From: "; 
    std::cin >> choice1;
    std::cout 
    << "2. What number system would you like to convert into? " << std::endl
    << "To: "; 
    std::cin >> choice2;

    int num = choices(choice1, choice2);
    repeat(numSysDisplayInput(num), choice2);
}

int choices(int num, int num1){                              //equation for switch statement in numSysDisplayInput
    if (num == 4 && num1 == 1){
        num = 523;
    } else {
        for (int i=0; i<num1; i++){
        num = num * num1;
        }
    }
    return num;
}

int numSysDisplayInput (int forSwitch){                     //user inputs data according to choice
    int value, result, RES;
    std::string cValue;

    switch (forSwitch){
        case 1:
            std::cout << "Enter Decimal value: ";
            std::cin >> value;
            std::cout << std::endl
            << " >> The Decimal value for " << value << " is " << value << std::endl;
            RES = value;
            break;

        case 4:
            std::cout << "(Limit of three(3) digits to avoid system failure)" << std::endl
            << "Enter Decimal value: ";
            std::cin >> value;
            std::cout << std::endl
            << ">> The Binary value for the Decimal [" <<
            value << "] is " << binary(value) << std::endl;
            RES = binary(value);
            break;

        case 27:
            std::cout << "Enter Decimal value: ";
            std::cin >> value;
            std::cout << std::endl
            << ">> The Octal value for the Decimal[" << value
            << "] is " << octal(value) << std::endl;
            RES = octal(value);
            break;

        case 256:
            std::cout << "Enter Decimal value: ";
            std::cin >> value;
            std::cout << std::endl
            << ">> The Hexadecimal value of the Decimal[" << value
            << "] is " << hexadecimal(value) << std::endl;
            RES = std::stoi (hexadecimal(value));
            break;

        case 2:
            std::cout << "Enter Binary value: "
            << "(Limit of ten(10) digits to avoid system failure)" << std::endl;
            std::cin >> value;
            std::cout << std::endl
            << ">> The Decimal Value of the Binary [" << value << "] is "
            << binConversion(value) << std::endl;
            RES = binConversion(value);
            break;

        case 8:
            std::cout << "Enter Binary Value: ";
            std::cin >> value;
            std::cout << std::endl
            << ">> The Binary Value of the Binary [" << value << "] is " <<
            value << std::endl;
            break;

        case 54:
            std::cout << "Enter Binary Value: "
            << "(Limit of ten(10) digits to avoid system failure)" << std::endl;
            std::cin >> value;
            std::cout << std::endl
            << ">> The Octal Value of the Binary [" << value << "] is "
            << octal(binConversion(value)) << std::endl;
            RES = octal(binConversion(value));
            break;

        case 3:
            std::cout << "Enter Octal Value: ";
            std::cin >> value;
            std::cout << std::endl
            << ">> The Decimal Value of the Octal [" << value << "] is "
            << octConversion(value) << std::endl;
            RES = octConversion(value);
            break;

        case 12:
            std::cout << "Enter Octal Value: ";
            std::cin >> value;
            std::cout << std::endl
            << ">> The Binary Value of the Octal [" << value << "] is "
            << binary(octConversion(value)) << std::endl;
            RES = binary(octConversion(value));
            break;

        case 81:
            std::cout << "Enter Octal Value: ";
            std::cin >> value;
            std::cout << std::endl
            <<">> The Octal Value of the Octal [" << value << "] is "
            << value << std::endl;
            RES = value;
            break;

        case 512:
            std::cout << "Enter Binary Value: "
            << "(Limit of ten(10) digits to avoid system failure)" << std::endl;
            std::cin >> value;
            std::cout << std::endl
            << ">> The Hexadecimal Value of the Binary [" << value << "] is "
            << hexadecimal(binConversion(value)) << std::endl;
            RES = stoi (hexadecimal(binConversion(value)));
            break;

        case 768:
            std::cout << "Enter Octal Value: ";
            std::cin >> value;
            std::cout << std::endl
            << ">> The Hexadecimal Value of the Octal [" << value << "] is "
            << hexadecimal (octConversion(value)) << std::endl;
            RES = stoi (hexadecimal(octConversion(value)));
            break;

        case 1024:
            std::cout << "Enter Hexadecimal Value: ";
            std::cin >> cValue;
            std::cout << std::endl
            << ">> The Hexadecimal Value of the Hexadecimal [" << cValue << "] is "
            << cValue << std::endl;
            RES = stoi (cValue);
            break;

        case 523:
            std::cout << "Enter Hexadecimal Value: ";
            std::cin >> cValue;
            std::cout << std::endl
            << ">> The Decimal Value of the Hexadecimal [" << cValue << "] is "
            << hexConversion(cValue) << std::endl;
            RES = hexConversion(cValue);
            break;

        case 16:
            std::cout << "Enter Hexadecimal Value: ";
            std::cin >> cValue;
            std::cout << std::endl
            << ">> The Binary Value of the Hexadecimal [" << cValue <<  "] is "
            << binary(hexConversion(cValue)) << std::endl;
            RES = binary(hexConversion(cValue));
            break;

        case 108:
            std::cout << "Enter Hexadecimal Value: ";
            std::cin >> cValue;
            std::cout << std::endl
            << ">> The Octal Value of the Hexadecimal [" << cValue <<  "] is "
            << octal(hexConversion(cValue));
            RES = octal(hexConversion(cValue));
            break;

        default:
            error();
            numSys();
    }
    return RES;
}

void numSysIntro (){                                               //introduction to user after user chooses to run the converter
    std::string numsys[] = {"Decimal", "Binary", "Octal", "Hexadecimal"};
    std::cout << std::endl 
    << "**NUMBER SYSTEMS CONVERTER**" << std::endl
    << "Version 2.1.0 (Beta)" << std::endl
    << "TABLE: " << std::endl;

    for (int i = 0; i <4; i++) {
        std::cout << "[" <<  i+1 << "] " << numsys[i] << std::endl;
    }
    std::cout << std::endl
    << "(Hexadecimal number system is in constant development)" << std::endl;
}

int binary (int num) {                                          //decimal to binary
    int numClone = num, reiteration =0, bin = 0, temp =1;

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

int octal (int num){                                           //decimal to octal
    int numClone = num;
    int mult = 1, rem = 0;

    while (numClone != 0){
        rem = rem + ((numClone % 8 ) * mult);
        numClone /= 8;
        mult *= 10;
    }
    return rem;
}

std::string hexadecimal (int num) {                           //decimal to hexadecimal
    int hde = num, hde1 = num, q, hdr, hdcounter =0;
    std::string HEXA;

    do {
        hde = hde / 16;
        hdcounter++;
    } while (hde != 0);

    int* hdcontainer = new int[hdcounter];

    for (int i = 0; i < hdcounter; i++){
        hdr = hde1 % 16;
        hde1 = hde1 /16;
        hdcontainer[i] = hdr;
    }

    std::string* Test = new std::string[hdcounter];
    std::string HDList[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    for (int i = 0; i <hdcounter; i++) {
        HEXA += HDList[hdcontainer[i]];
   }
   reverse(HEXA.begin(), HEXA.end());
   return HEXA;
}

void repeat (int num, int num1){                            //options for user after converting 
    char answer;
    std::cout << std::endl 
    << "[SELECT ACTION]" << std::endl
    << "[1] Repeat from start" << std::endl
    << "[2] Convert result to another number system" << std::endl
    << "[3] Read the program info" << std::endl
    << "[4] Exit program" << std::endl
    << ">> "; std:: cin >> answer;
    std::cout << "________________________________________________________________________________________________" << std::endl;
    
    switch (answer){
        case '1':
            numSys(); break;

        case '2':
            cont(num, num1); break;

        case '3':
            programDisclaimer(); break;

        case '4':
            exit(); break;

        default:
            error();
            repeat(num, num1);
    }
}

int cont (int num, int num1){                               //continuation after user chooses to convert again
    int choice;
    char reload;
    std::cout << std::endl;
    numSysIntro();
    std::cout << std::endl 
    << "Select number system to convert into: ";
    std::cin >> choice;

    int forSwitch2 = choices(num1, choice);
    numSysSecondPhase(forSwitch2, num, num1);
    
    exit();
    std::cout << "(Multiple conversions is not supported in Beta)" << std::endl << std::endl
    << "PRESS [1] TO RELOAD THE CONVERTER " << std::endl
    << "PRESS [2] TO READ INFO" << std::endl
    << ">> ";
    std::cin >> reload;
    std::cout << "________________________________________________________________________________________________" << std::endl;

    switch (reload){
        case '1':
            numSys(); break;

        case '2':
            programDisclaimer(); break;
    }
    return 0;
}

void numSysSecondPhase (int num, int bin, int num1){        //second conversion
    std::stringstream stream;
    stream << bin;
    std::string str;
    stream >> str;

    switch (num){
        case 2:
            std::cout << std::endl
            << ">> The Decimal Value of the Binary [" << bin << "] is "
            << binConversion(bin) << std::endl;
            break;

        case 3:
            std::cout << std::endl
            << ">> The Decimal value of the Octal [" << bin << "] is "
            << octConversion(bin) << std::endl;
            break;

        case 12:
            std::cout << std::endl
            << ">> The Binary Value of the Octal [" << bin << "] is "
            << binary(octConversion(bin)) << std::endl;
            break;

        case 81:
            std::cout << std::endl
            << ">> The Octal Value of the Octal [" << bin << "] is "
            << bin << std::endl;
            break;

        case 256:
            std::cout << std::endl
            << ">> The Hexadecimal value of the Decimal[" << bin
            << "] is " << hexadecimal(bin) << std::endl;
            break;

        case 8:
            std::cout << std::endl
            << ">> The Binary Value of the Binary [" << bin << "] is " <<
            bin << std::endl;
            break;

        case 54:
            std::cout << std::endl
            << ">> The Octal Value of the Binary [" << bin << "] is "
            << octal(binConversion(bin)) << std::endl;
            break;

        case 1:
            std::cout << std::endl
            << ">> The Decimal value of " << bin << " is " << bin << std::endl;
            break;

        case 4:
            std::cout << std::endl
            << ">> The Binary value of the Decimal [" <<
            bin << "] is " << binary(bin) << std::endl;
            break;

        case 27:
            std::cout << std::endl
            << ">> The Octal value of the Decimal[" << bin
            << "] is " << octal(bin) << std::endl;
            break;

        case 512:
            std::cout << std::endl
            << ">> The Hexadecimal Value of the Binary [" << bin << "] is "
            << hexadecimal(binConversion(bin)) << std::endl;
            break;

        case 768:
            std::cout << std::endl
            << ">> The Hexadecimal Value of the Octal [" << bin << "] is "
            << hexadecimal (octConversion(bin)) << std::endl;
            break;

        case 1024:
            std::cout << std::endl
            << ">> The Hexadecimal Value of the Hexadecimal [" << str << "] is "
            << str << std::endl;
            break;

        case 523:
            std::cout << std::endl
            << ">> Decimal Value of the Hexadecimal [" << str << "] is "
            << hexConversion(str) << std::endl;
            break;

        case 16:
            std::cout << std::endl
            << ">> The Binary Value of the Hexadecimal [" << str <<  "] is "
            << binary(hexConversion(str)) << std::endl;
            break;

        case 108:
            std::cout << std::endl
            << ">> The Octal Value of the Hexadecimal [" << str <<  "] is "
            << octal(hexConversion(str)) << std::endl;
            break;

        default:
            error();
            cont(bin, num1);
    }
}

int binConversion (int num){                            //binary to decimal
    int DEC = 0, REM = 0, j = 0;
    while (num != 0){
        REM = num % 10;
        num /= 10;
        DEC += REM * pow (2, j);
        j++;
    }
    return DEC;
}

int octConversion (int num){                            //octal to decimal
     int deci = 0, i = 0, rem;
      while (num != 0){
      rem = num % 10;
      deci = deci + (rem* pow(8, i));
      i++;
      num = num / 10;
   }
   return deci;
}

int hexConversion (std::string numS){                  //hexadecimal to decimal
    int len = numS.length();
    int base = 1;
    int res = 0;
    for (int i=len-1; i>=0; i--){
         if (numS[i]>='0' && numS[i]<='9'){
         res += (numS[i] - 48)*base;
         base = base * 16;
      }
      else if (numS[i]>='A' && numS[i]<='F'){
         res += (numS[i] - 55)*base;
         base = base*16;
      }
   }
   return res;
}

void error (){                                       //function is called when user chooses an invalid option
    std::cout << std::endl
    << "[ERROR] INVALID INPUT" << std::endl
    << "Reloading..." << std::endl;
}

void exit (){                                       //function is called when the user wants to exit the program
    std::cout << std::endl 
    << "[END OF PROGRAM] Thank you for your patronage :>" << std::endl; 
}

void programDisclaimer (){                          //a void function to display the information of the program
    char choice;
    std::cout << std::endl
    << "[1] INFO: " << std::endl
    << "    Developer name:\tJann Louie Q. Almirante" << std::endl
    << "    Course:\t\tComputer Engineering I" << std::endl
    << "    Subject:\t\tCOE 131 | PROGRAMMING LOGIC AND DESIGN" << std::endl
    << "    Professor:\t\tEng. Don Opada" << std::endl
    << "    University:\t\tNegros Oriental State University (NORSU)" << std::endl << std::endl
    << "[2] PPROGRAM CONSISTS OF: " << std::endl
    << "    (a) CONDITIONAL OPERATORS" << std::endl
    << "    (b) ARRAYS" << std::endl
    << "    (c) LOOPS" << std::endl
    << "    (d) FUNCTIONS" << std::endl
    << "    (e) POINTERS" << std::endl << std::endl
    << "[3] CONVERTER INFO:" << std::endl
    << "    - A program that converts any number system to another number system" << std::endl
    << "    - Input a number that is not too big for program to work flawlessly" << std::endl
    << "    - More instructions are stated within the program" << std::endl << std::endl
    << "FOR CONDITIONAL BUGS: {this is a problem encountered in Hexadecimal conversion}" << std::endl
    << "[1] If program ends without the message >> \"[END OF PROGRAM]\":" << std::endl
    << "    (a) Manually reload program and" << std::endl
    << "    (b) Input a smaller number next time" << std::endl << std::endl
    << "Rest assured that the program works accurately if program does not encounter any problems" << std::endl << std::endl
    << "Thank you for your time!" << std::endl << std::endl
    << "PRESS [1] TO START THE CONVERTER " << std::endl
    << "PRESS [2] TO EXIT PROGRAM" << std::endl
    << ">> ";
    std:: cin >> choice;
    std::cout << "________________________________________________________________________________________________" << std::endl;

    switch (choice){
        case '1':
            numSys(); break;

        case '2':
            exit(); break;

        default:
            error();
            programDisclaimer();
    }
}//Whaaat