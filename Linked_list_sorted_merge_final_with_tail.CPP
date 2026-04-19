#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void insertend(Node* &head, int data){

	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	if(head==nullptr){
		head=newNode;
		return;
	}

	Node* temp = head;
	while(temp->next != nullptr){
		temp=temp->next;
	}
	temp->next = newNode;
}

void sortedmerge(Node* head1, Node* head2, Node* &head3) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* tail = nullptr; // Keeps track of the last node in head3

    auto addNode = [&](int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head3 == nullptr) {
            head3 = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    };

    // Main comparison loop
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data <= temp2->data) {
            addNode(temp1->data);
            temp1 = temp1->next;
        } else {
            addNode(temp2->data);
            temp2 = temp2->next;
        }
    }

    // Attach remaining nodes
    while (temp1 != nullptr) {
        addNode(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr) {
        addNode(temp2->data);
        temp2 = temp2->next;
    }
}

void print(Node* head){
	Node* temp= head;
	while(temp!=nullptr){
		cout<< "  " << temp->data << " ";
		temp=temp->next;
	}
}

int main(){
	Node* head1 =nullptr;
	Node* head2 =nullptr;
	Node* head3=nullptr;

	int n1;
	cout<<"ENter the number of nodes in list 1 : ";
	cin>>n1;
	cout << "enter the elements : \n";
	for(int i=0; i<n1 ; i++){
		int data;
		cin>>data;
		insertend(head1,data);
	}	

	int n2;
	cout<<"ENter the number of nodes in list 2 : ";
	cin>>n2;
	cout << "enter the elements : \n";
	for(int i=0; i<n2 ; i++){
		int data;
		cin>>data;
		insertend(head2,data);
	}

	sortedmerge(head1,head2,head3);
	print(head3);

	return 0;
}