#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidIdentifier(const string& str) {
    if (str.empty())
        return false;

    if (!isalpha(str[0]) && str[0] != '_')
        return false;


    for (size_t i = 1; i < str.length(); ++i) {
        if (!isalnum(str[i]) && str[i] != '_')
            return false;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    if (isValidIdentifier(input)) {
        cout << "This is a valid identifier." << endl;
    } else {
        cout << "This is NOT a valid identifier." << endl;
    }

    return 0;
}

