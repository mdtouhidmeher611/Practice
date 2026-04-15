#include <iostream>
#include <string>
#include <stack>
#include <cmath> // Required for pow()

using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<float> operand; // Changed to float for accurate math (e.g., division)

    // First loop: replace variables with values
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            int val;
            cout << "Enter the value of '" << s[i] << "' :";
            cin >> val;
            // Store the digit back into the string
            s[i] = val + '0'; 
        }
    }

    // Second loop: calculate
    for (int i = 0; i < s.length(); i++) {
        // Skip spaces
        if (s[i] == ' ') continue;

        // Condition fixed using &&
        if (s[i] >='0' && s[i]<= '9') {
            operand.push(s[i] - '0');
        }
        else {
            // Correct way to pop in C++
            float a = operand.top(); operand.pop();
            float b = operand.top(); operand.pop();
            float c;

            if (s[i] == '*')
                c = b * a;
            else if (s[i] == '/')
                c = b / a;
            else if (s[i] == '+')
                c = b + a;
            else if (s[i] == '-')
                c = b - a;
            else if (s[i] == '^')
                c = pow(b, a);

            operand.push(c);
        }
    }

    if (!operand.empty()) {
        cout << "Result: " << operand.top() << endl;
    }

    return 0;
}