#include <iostream>
#include <cctype>
using namespace std;

bool isNumericConstant(string input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return !input.empty();  // Make sure it's not empty
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    if (isNumericConstant(input)) {
        cout << "This is a numeric constant." << endl;
    } else {
        cout << "This is NOT a numeric constant." << endl;
    }

    return 0;
}

