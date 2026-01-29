#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to traverse and display linked list
void traverse(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;  // move to the next node
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    // Creating nodes
    head = new Node();
    second = new Node();
    third = new Node();

    // Assigning data
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    // Traverse and print the list
    traverse(head);

    return 0;
}
