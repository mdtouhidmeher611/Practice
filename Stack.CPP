#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

// Push operation
void push(int item) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = item;
    cout << "Pushed: " << item << endl;
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stackArr[top--] << endl;
}

// Display stack
void display() {
    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Stack elements:\n";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, item;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item: ";
                cin >> item;
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 4);

    return 0;
}