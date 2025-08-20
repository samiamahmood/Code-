#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_set>

using namespace std;


void detectToken(const string& token) {
    unordered_set<string> operators = { "+", "-", "*", "/", "=", "==", "!=", "<", "<=", ">", ">=" };

    if (token == ";")
        cout << "[Semicolon] => " << token << endl;
    else if (operators.count(token))
        cout << "[Operator] => " << token << endl;
    else if (regex_match(token, regex("^\\d+$")))
        cout << "[Number] => " << token << endl;
    else if (regex_match(token, regex("^[a-zA-Z_][a-zA-Z0-9_]*$")))
        cout << "[Variable] => " << token << endl;
    else
        cout << "[Unknown] => " << token << endl;
}

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    string token;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (isspace(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else if (ispunct(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }

            if (i + 1 < line.size()) {
                string twoChar = string(1, c) + line[i + 1];
                unordered_set<string> twoCharOps = { "==", "!=", "<=", ">=" };
                if (twoCharOps.count(twoChar)) {
                    tokens.push_back(twoChar);
                    ++i;
                    continue;
                }
            }

            tokens.push_back(string(1, c));
        }
        else {
            token += c;
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    string path = "text.txt";
    ifstream file(path);

    if (!file.is_open()) {
        cout << "Failed to open file.\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        vector<string> tokens = tokenize(line);
        for (const string& t : tokens) {
            detectToken(t);
        }
    }

    file.close();
    return 0;
}



