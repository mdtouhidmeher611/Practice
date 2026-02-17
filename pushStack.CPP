#include <iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = value;
    cout << "Inserted: " << value << endl;
}

int main() {
    int value;
    cout << "Enter value to push: ";
    cin >> value;
    push(value);
    return 0;
}
