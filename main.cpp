#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <cctype>

using namespace std;

// Define sets for keywords, operators, separators
unordered_set<string> keywords = {
    "int", "float", "char", "double", "if", "else", "for", "while", "return", "break", "continue", "void", "bool", "true", "false"
};

unordered_set<char> operators = {
    '+', '-', '*', '/', '%', '=', '<', '>', '!', '&', '|', '^'
};

unordered_set<char> separators = {
    '(', ')', '{', '}', '[', ']', ';', ',', '.'
};

// Function to check if a string is a number
bool isNumber(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return !str.empty();
}

// Function to classify a token
void classifyToken(const string& token) {
    if (token.empty()) return;

    if (keywords.find(token) != keywords.end()) {
        cout << token << " : Keyword" << endl;
    }
    else if (isNumber(token)) {
        cout << token << " : Number" << endl;
    }
    else if (token.length() == 1 && operators.find(token[0]) != operators.end()) {
        cout << token << " : Operator" << endl;
    }
    else if (token.length() == 1 && separators.find(token[0]) != separators.end()) {
        cout << token << " : Separator" << endl;
    }
    else {
        cout << token << " : Identifier" << endl;
    }
}

int main() {
    string line;
    cout << "Enter a line of C++ code: "<<endl;
    getline(cin, line);

    string token;
    for (size_t i = 0; i < line.length(); ++i) {
        char ch = line[i];

        if (isspace(ch)) {
            classifyToken(token);
            token.clear();
        }
        else if (operators.find(ch) != operators.end() || separators.find(ch) != separators.end()) {
            classifyToken(token);
            token.clear();
            string op(1, ch);
            classifyToken(op);
        }
        else {
            token += ch;
        }
    }
    classifyToken(token); // classify the last token if any

    return 0;
}

