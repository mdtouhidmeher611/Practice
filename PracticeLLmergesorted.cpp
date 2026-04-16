#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Standard insert function
void insert(Node*& head, int newdata) {
    Node* newNode = new Node();
    newNode->data = newdata;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

// Function to merge two sorted lists
Node* mergeSorted(Node* headA, Node* headB) {
    // Create a dummy node to act as the start of the result list
    Node dummy; 
    Node* tail = &dummy;
    dummy.next = nullptr;

    while (headA != nullptr && headB != nullptr) {
        if (headA->data <= headB->data) {
            tail->next = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            headB = headB->next;
        }
        tail = tail->next;
    }

    // If one list finishes, attach the rest of the other list
    if (headA != nullptr) tail->next = headA;
    else tail->next = headB;

    return dummy.next;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *A = nullptr, *B = nullptr;
    int n, m, val;

    cout << "Enter size and sorted elements for A: ";
    cin >> n;
    while(n--) { cin >> val; insert(A, val); }

    cout << "Enter size and sorted elements for B: ";
    cin >> m;
    while(m--) { cin >> val; insert(B, val); }

    Node* result = mergeSorted(A, B);
    cout << "Merged Sorted List: ";
    print(result);

    return 0;
}