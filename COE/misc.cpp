#include <iostream>
using namespace std;

int main() {
    int c1, c2;

    cout << "[1] Decimal\n"
    << "[2] Binary\n"
    << "[3] Octal\n"
    << "[4] Hexadecimal\n\n";

    cout << "Enter a choice: ";
    cin >> c1;
    cout << "Enter another choice: ";
    cin >> c2;

    if (c1 == 4 && c2 == 1){
        c1 = 523;
    }
    else {
        for (int i=0; i<c2; i++){
            c1 = c1 * c2;
        }
    }
    cout << "\nResult: " << c1 << "\n\n";

    main();
}
