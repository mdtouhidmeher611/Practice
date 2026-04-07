#include <iostream>
using namespace std;

#define MAX 100

int queueArr[MAX];
int front = -1, rear = -1;

// Enqueue Operation
void enqueue(int item) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) front = 0;
    queueArr[++rear] = item;
    cout << "Inserted: " << item << endl;
}

// Dequeue Operation
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Deleted: " << queueArr[front++] << endl;
}

// Peek Operation
void peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Front element: " << queueArr[front] << endl;
}

// Display Queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue elements:\n";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, item;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item: ";
                cin >> item;
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    } while (choice != 5);

    return 0;
}