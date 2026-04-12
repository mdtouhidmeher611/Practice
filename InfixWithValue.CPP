#include <iostream>
#include <stack>
#include <cmath>
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

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    getline(cin, infix);

    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Ignore spaces
        if (c == ' ') continue;

        // If digit
        if (isdigit(c)) {
            int val = 0;
            while (i < infix.length() && isdigit(infix[i])) {
                val = val * 10 + (infix[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }

        // If letter (ask user input)
        else if (isalpha(c)) {
            int value;
            cout << "Enter value for " << c << " (single digit): ";
            cin >> value;
            values.push(value);
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
    }

    // Final evaluation
    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    cout << "Final Result = " << values.top() << endl;

    return 0;
}