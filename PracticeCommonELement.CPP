#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insert(Node* &head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void common(Node* head1, Node* head2){
    if(head1 == nullptr || head2 == nullptr){
        cout << "No common node\n";
        return;
    }

    Node* temp1 = head1;
    int found = 0;

    cout << "Intersection: ";

    while(temp1 != nullptr){
        Node* temp2 = head2;   // ✅ reset for each node of list1

        while(temp2 != nullptr){
            if(temp1->data == temp2->data){
                cout << temp1->data << " --> ";
                found = 1;
                break;  // avoid duplicate prints
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;  // ✅ correct movement
    }

    if(found == 0){
        cout << "No common node found";
        return;
    }

    cout << "NULL\n";
}

int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    int n1;
    cout << "No of elements of first list: ";
    cin >> n1;

    for(int i = 0; i < n1; i++){
        int data;
        cin >> data;
        insert(head1, data);
    }

    int n2;
    cout << "No of elements of second list: ";
    cin >> n2;

    for(int i = 0; i < n2; i++){
        int data;
        cin >> data;
        insert(head2, data);
    }

    common(head1, head2);

    return 0;
}