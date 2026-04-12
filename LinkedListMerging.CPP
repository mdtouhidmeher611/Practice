#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList(int n) {
    Node *head = nullptr, *temp = nullptr, *newNode = nullptr;
    int value;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node* mergeLists(Node* head1, Node* head2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != nullptr)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

int main() {
    int n1, n2;

    cout << "Enter number of nodes for List 1: ";
    cin >> n1;
    Node* head1 = createList(n1);

    cout << "Enter number of nodes for List 2: ";
    cin >> n2;
    Node* head2 = createList(n2);

    cout << "\nList 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    Node* mergedHead = mergeLists(head1, head2);

    cout << "\nMerged Sorted List: ";
    display(mergedHead);

    return 0;
}