#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    string infix, postfix = "";
    stack<char> st;

    cout << "Enter Infix Expression: ";
    getline(cin, infix);   // take full line including spaces

    cout << "\nStep\tSymbol\tStack\tPostfix\n";
    cout << "------------------------------------------\n";

    int step = 1;

    for (char c : infix) {

        // ✅ Ignore spaces
        if (c == ' ')
            continue;

        cout << step++ << "\t" << c << "\t";

        // Operand
        if (isalnum(c)) {
            postfix += c;
        }
        // Opening bracket
        else if (c == '(') {
            st.push(c);
        }
        // Closing bracket
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // Operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }

        // Print stack contents
        stack<char> temp = st;
        string stackContent = "";
        while (!temp.empty()) {
            stackContent = temp.top() + stackContent;
            temp.pop();
        }

        cout << stackContent << "\t" << postfix << endl;
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "\nFinal Postfix Expression: " << postfix << endl;

    return 0;
}