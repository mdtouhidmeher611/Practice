#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else{
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteBeginning(){
    if(head == NULL){
        cout<<"List Empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd(){
    if(head == NULL){
        cout<<"List Empty\n";
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void deleteValue(int val){
    if(head == NULL){
        cout<<"List Empty\n";
        return;
    }

    if(head->data == val){
        deleteBeginning();
        return;
    }

    Node* temp = head;
    while(temp->next != NULL && temp->next->data != val)
        temp = temp->next;

    if(temp->next == NULL){
        cout<<"Value not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
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
    int n, x, choice;

    cout<<"Enter number of nodes: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        insert(x);
    }

    while(true){
        cout<<"\n1.Delete Beginning\n2.Delete End\n3.Delete by Value\n4.Display\n5.Exit\nChoice: ";
        cin>>choice;

        if(choice==1) deleteBeginning();
        else if(choice==2) deleteEnd();
        else if(choice==3){
            cout<<"Enter value: ";
            cin>>x;
            deleteValue(x);
        }
        else if(choice==4) display();
        else break;
    }
}