#include <iostream>
#include <stack>
#include <map>

using namespace std;

enum BraceType {parenthesis, bracket, curly};
map <char, BraceType> bracemap {
        {')', parenthesis},
        {'(', parenthesis},
        {'[', bracket},
        {']', bracket},
        {'{', curly},
        {'}', curly},
};

bool valid_braces(std::string braces) {
    stack<char> bracestack;
    for (auto c: braces) {
        if (c == '(' || c == '[' || c == '{') bracestack.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (bracestack.empty() || bracemap[bracestack.top()] != bracemap[c]) return false;
            bracestack.pop();
        }
    }
    if (! bracestack.empty()) return false;
    return true;
}