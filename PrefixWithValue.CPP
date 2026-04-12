#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    getline(cin, prefix);

    stack<int> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // Ignore spaces
        if (c == ' ') continue;

        // If digit
        if (isdigit(c)) {
            st.push(c - '0');
        }
        // If letter, ask value
        else if (isalpha(c)) {
            int value;
            cout << "Enter value for " << c << " (single digit): ";
            cin >> value;
            st.push(value);
        }
        // If operator
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int result = applyOp(a, b, c);
            st.push(result);
        }
    }

    cout << "Final Result = " << st.top() << endl;

    return 0;
}