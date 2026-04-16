#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};


void print(Node* head){
	Node* temp= head;
	while(temp!=nullptr){
		cout << temp->data << "-->";
		temp = temp->next;
	}
}

void atbegining(Node*& head , int newData){
	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next= head;
	head= newNode;
}

void atend(Node*& head , int newData){
		Node* newNode = new Node();
	newNode->data = newData;
	newNode->next= nullptr;

	if(head = nullptr){
		head= newNode;
		return;
	}

	Node* temp = head;
	while(temp->next !=nullptr){
		temp=temp->next;
	}
	temp->next= newNode;
}

void after(Node* prevNode, int newData){
	   if (prevNode == nullptr) {
        cout << "Previous node cannot be NULL!" << endl;
        return;
    }
      if (prevNode == nullptr) {
        cout << "Previous node cannot be NULL!" << endl;
        return;
    }


}