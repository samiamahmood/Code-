#include <iostream>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=');
}

int main() {
    string input;
    cout << "Enter an expression : ";
    cin >> input;

    int count = 1;
    for (char c : input) {
        if (isOperator(c)) {
            cout << "operator" << count << ": " << c << endl;
            count++;
        }
    }

    if (count == 1) {
        cout << "No arithmetic operators found." << endl;
    }

    return 0;
}

