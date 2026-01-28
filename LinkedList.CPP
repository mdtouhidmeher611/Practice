#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert at the beginning
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {  // If list is empty
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Insert after a specific node (by value)
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be NULL!" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int main() {
    Node* head = nullptr;

    // Add elements
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    cout << "Initial list: ";
    printList(head);

    // Insert at beginning
    insertAtBeginning(head, 5);
    cout << "After inserting 5 at beginning: ";
    printList(head);

    // Insert after 20
    insertAfter(head->next->next, 25); // head->next->next is node 20
    cout << "After inserting 25 after 20: ";
    printList(head);

    // Insert at end
    insertAtEnd(head, 40);
    cout << "After inserting 40 at end: ";
    printList(head);

    return 0;
}
