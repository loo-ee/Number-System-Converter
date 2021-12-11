void programDisclaimer (){                          //a void function to display the information of the program
    char choice;
    std::cout << std::endl
    << "[1] INFO: " << std::endl
    << "    Developer name:\tJann Louie Q. Almirante" << std::endl
    << "    Course:\t\tComputer Engineering I" << std::endl
    << "    Subject:\t\tCOE 131 | PROGRAMMING LOGIC AND DESIGN" << std::endl
    << "    Professor:\t\tENG. Don Opada" << std::endl
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
    << "    (a) Manually reload program or" << std::endl
    << "    (b) Input a smaller number" << std::endl << std::endl
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
}