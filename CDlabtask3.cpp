#include <iostream>
#include <string>
using namespace std;

bool isSingleLineComment(const string& line) {
    return line.substr(0, 2) == "//";
}

bool isMultiLineComment(const string& line) {
    return line.substr(0, 2) == "/*" && line.size() >= 4 && line.substr(line.size() - 2) == "*/";
}

int main() {
    string input;
    cout << "Enter a line: ";
    getline(cin, input);

    if (isSingleLineComment(input)) {
        cout << "This is a single-line comment." << endl;
    }
    else if (isMultiLineComment(input)) {
        cout << "This is a multi-line comment." << endl;
    }
    else {
        cout << "This is NOT a comment." << endl;
    }

    return 0;
}

