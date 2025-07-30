#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <unordered_set>
using namespace std;

unordered_set<string> keywords = {
    "int", "float", "double", "char", "if", "else", "for", "while", "return", "void"
};


unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=",
    ">", "<", ">=", "<=", "&&", "||"
};

bool isValidIdentifier(const string& token) {
    if (token.empty()) return false;
    if (!(isalpha(token[0]) || token[0] == '_')) return false;
    for (int i = 1; i < token.size(); ++i) {
        if (!(isalnum(token[i]) || token[i] == '_'))
            return false;
    }
    return true;
}

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    string token;

    for (size_t i = 0; i < line.size(); ++i) {
        char ch = line[i];

        if (isspace(ch)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            continue;
        }

        string twoCharOp = line.substr(i, 2);
        if (operators.count(twoCharOp)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(twoCharOp);
            i++;
            continue;
        }

        string oneCharOp(1, ch);
        if (operators.count(oneCharOp)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(oneCharOp);
            continue;
        }

        token += ch;
    }

    if (!token.empty())
        tokens.push_back(token);

    return tokens;
}

int main() {
    ifstream file("input.cpp");
    if (!file.is_open()) {
        cerr << "Error: Cannot open input.cpp!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        vector<string> tokens = tokenize(line);

        for (const string& token : tokens) {
            if (keywords.count(token)) {
                cout << token << " → keyword" << endl;
            } else if (operators.count(token)) {
                cout << token << " → operator" << endl;
            } else if (isValidIdentifier(token)) {
                cout << token << " → valid identifier" << endl;
            } else if (isdigit(token[0])) {
                cout << token << " → numeric constant" << endl;
            } else {
                cout << token << " → invalid identifier or unknown" << endl;
            }
        }
    }

    file.close();
    return 0;
}


