#include <iostream>
#include "numberSystemClass.h"
using namespace std;

int main () {
    long long int val;
    NumberSystem newClass;

    cout << "Enter a long long int: ";
    cin >> val;

    newClass.setIntResult(val);
    cout << "Value: " << newClass.getIntResult() << endl;
}