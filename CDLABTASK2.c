#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <cctype>
using namespace std;


unordered_set<string> keywords = {
    "int", "float", "double", "char", "if", "else", "for", "while",
    "return", "void";
};


unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", "<=", ">", ">=", "&&", "||", "!", "++", "--"
};

bool isValidIdentifier(const string &s) {
    if (s.empty()) return false;
    if (!(isalpha(s[0]) || s[0] == '_')) return false;
    for (size_t i = 1; i < s.size(); i++) {
        if (!(isalnum(s[i]) || s[i] == '_')) return false;
    }
    return true;
}

int main() {
    ifstream file("input.cpp");
    if (!file.is_open()) {
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        string token;
        stringstream ss(line);
        while (ss >> token) {
            if (keywords.find(token) != keywords.end()) {
                cout << token << " : Keyword" << endl;
            } else if (operators.find(token) != operators.end()) {
                cout << token << " : Operator" << endl;
            } else if (isValidIdentifier(token)) {
                cout << token << " : Valid Identifier" << endl;
            } else {
                cout << token << " : Invalid Identifier / Unknown" << endl;
            }
        }
    }

    file.close();
    return 0;
}

