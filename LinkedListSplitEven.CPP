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

// Count nodes
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Split list
void splitList(Node* head, Node*& front, Node*& back) {
    int n = countNodes(head);

    int mid = n / 2;   // IMPORTANT: floor division → extra goes to BACK

    Node* temp = head;

    front = head;

    // move to last node of front list
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        back = temp->next;
        temp->next = NULL;
    }
}

int main() {
    Node* head = NULL;
    Node* front = NULL;
    Node* back = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
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