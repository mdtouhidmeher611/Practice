#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print list
void printList(Node* head) {
    cout << "{ ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "}" << endl;
}

// Split list into front and back halves
void splitList(Node* head, Node*& front, Node*& back) {
    Node* slow = head;
    Node* fast = head;

    if (head == NULL || head->next == NULL) {
        front = head;
        back = NULL;
        return;
    }

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    front = head;
    back = slow->next;
    slow->next = NULL;
}

int main() {
    Node* head = NULL;
    Node* front = NULL;
    Node* back = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements of linked list:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(head, value);
    }

    cout << "\nOriginal List: ";
    printList(head);

    splitList(head, front, back);

    cout << "Front List: ";
    printList(front);

    cout << "Back List: ";
    printList(back);

    return 0;
}