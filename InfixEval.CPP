#include <iostream>
#include<cmath>
#include <stack>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}

// Print stack contents
void printIntStack(stack<int> s) {
    vector<int> v;
    while (!s.empty()) { v.push_back(s.top()); s.pop(); }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}

void printCharStack(stack<char> s) {
    vector<char> v;
    while (!s.empty()) { v.push_back(s.top()); s.pop(); }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    getline(cin, infix);

    stack<int> values;
    stack<char> ops;

    cout << "\nStep\tSymbol\tValues Stack\tOperators Stack\n";
    cout << "-------------------------------------------------------------\n";

    int step = 1;

    for (int i = 0; i < infix.length(); i++) {

        char c = infix[i];

        if (c == ' ') continue;

        cout << step++ << "\t" << c << "\t";

        // If digit, read full number
        if (isdigit(c)) {
            int val = 0;
            while (i < infix.length() && isdigit(infix[i])) {
                val = val * 10 + (infix[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
        // Opening bracket
        else if (c == '(') {
            ops.push(c);
        }
        // Closing bracket
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            if (!ops.empty()) ops.pop();
        }
        // Operator
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(c);
        }

        printIntStack(values);
        cout << "\t\t";
        printCharStack(ops);
        cout << endl;
    }

    // Final evaluation
    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    cout << "\nFinal Result = " << values.top() << endl;

    return 0;
}