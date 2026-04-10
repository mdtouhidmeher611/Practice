#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to print current stack contents
void printStack(stack<int> s)
{
    vector<int> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }

    // Print from bottom to top
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    string postfix;

    cout << "Enter postfix expression (space separated): ";
    getline(cin, postfix);

    stringstream ss(postfix);
    string token;

    cout << "\nStep\tSymbol\tAction\t\t\tStack\n";
    cout << "------------------------------------------------------------\n";

    int step = 1;

    while (ss >> token) {

        cout << step << "\t" << token << "\t";

        // If operand
        if (isdigit(token[0])) {
            int num = stoi(token);
            st.push(num);
            cout << "Push " << num << "\t\t";
            printStack(st);
        }
        // If operator
        else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            int result;

            if (token == "+") result = op1 + op2;
            else if (token == "-") result = op1 - op2;
            else if (token == "*") result = op1 * op2;
            else if (token == "/") result = op1 / op2;

            st.push(result);

            cout << "Pop " << op1 << "," << op2 
                 << " -> Push " << result << "\t";
            printStack(st);
        }

        step++;
    }

    cout << "\nFinal Result = " << st.top() << endl;

    return 0;
}