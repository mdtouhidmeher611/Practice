#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;


void insert(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;

    if(head == nullptr)
        head = newNode;
    else{
        Node* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void sortList(){
    if(head == NULL){
        cout<<"List is empty\n";
        return;
    }

    Node* ptr;
    int swapped;

    do{
        ptr = head;
        swapped = 0;

        while(ptr->next != NULL){
            if(ptr->data > ptr->next->data){
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }

    }while(swapped);
}


void display(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


int main(){
    int n, x;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++){
        cin>>x;
        insert(x);
    }

    sortList();

    cout<<"Sorted List: ";
    display();
}