#include <iostream>
#include <stack>
#include <map>

using namespace std;

map <char, int> precedences = {
        {'(', 0},{'+', 1},{'-', 1},{'*', 2},{'/', 2},{'^', 3},
};

string to_postfix(const string &infix) {
    string postfix;
    stack<char> opstack;
    for (auto c: infix) {
        if (isdigit(c)) postfix.append(1, c);
        else if (c == '(') opstack.push(c);
        else if (c == ')') {
            while (opstack.top() != '(') {
                postfix.append(1,opstack.top());
                opstack.pop();
            }
            opstack.pop();
        } else {
            while (! opstack.empty() && precedences[opstack.top()] >= precedences[c]) {
                postfix.append(1, opstack.top());
                opstack.pop();
            }
            opstack.push(c);
        }
    }

    while (! opstack.empty()) {
        postfix.append(1, opstack.top());
        opstack.pop();
    }
    return postfix;
}