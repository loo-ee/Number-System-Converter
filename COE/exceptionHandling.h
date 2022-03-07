#pragma once
using namespace std;

class DecimalOverloading {
private:
    int decimal;

public:
    DecimalOverloading(int decimalValue) {
        this->decimal = decimalValue;
    }

    int getDecimalError() {
        return this->decimal;
    }
};

class IncorrectDecimal {
private:
    string intToStringDecimalValue;

public:
    IncorrectDecimal(string decimalValue) {
        this->intToStringDecimalValue = decimalValue;
    }

    string getDecimalError() {
        return this->intToStringDecimalValue;
    }
};


class BinaryOverloading {
private:
    int binaryCount;

public:
    BinaryOverloading(int count) {
        this->binaryCount = count;
    }

    int getBinaryError() {
        return this->binaryCount;
    }
};

class IncorrectBinary {
private:
    string intToStringBinaryValue;

public:
    IncorrectBinary(string binaryValue) {
        this->intToStringBinaryValue = binaryValue;
    }

    string getBinaryError() {
        return this->intToStringBinaryValue;
    }
};

class OctalOverloading {
private:
    int octalCount;

public:
    OctalOverloading(int count) {
        this->octalCount = count;
    }

    int getOctalError() {
        return this->octalCount;
    }
};

class IncorrectOctal {
private:
    string intToStringOctalValue;

public:
    IncorrectOctal(string octalValue) {
        this->intToStringOctalValue = octalValue;
    }

    string getOctalError() {
        return this->intToStringOctalValue;
    }
};
