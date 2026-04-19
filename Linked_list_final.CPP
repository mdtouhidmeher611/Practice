#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void insertbegin(Node* &head,int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next =head;
	head=newNode;
}

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

insertafter(Node* head, int n){

	Node* newNode = new Node();
	newNode->data = data;

	Node* temp= head;
	int nodecount=1;
	while(temp!=nullptr && nodecount<=n){
		temp=temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode

}	

void deletebegin(Node* &head){
	if(head== nullptr){
		cout << "List is already empty "<<endl;
		return;
	}

	Node* temp = head;
	head=head->next;
	cout<< " deleted : "<<temp->next<<endl;
	delete temp;

}

void deleteend(Node* &head){

	if(head== nullptr){
		cout << "List is already empty "<<endl;
		return;
	}

	if(head->next==nullptr){
		cout<<"Deleted : "<< head->data;
		delete head;
		head= nullptr;
		return;
	}

	Node* temp=head;
	while(temp->next->next!=nullptr){
		temp=temp->next;
	}

	Node* temp2= temp->next;
	cout<< "delete : "<< temp2->data<<endl;
	 temp->next = nullptr;
	 delete temp2;

}

void deletecertain(Node* head , int n){

	if(head== nullptr){
		cout << "List is already empty "<<endl;
		return;
	}

	if (n==1){
		delete<<"Deleted : " << head->data <<endl;
		delete head;
		head= nullptr;
		return;
	}

	Node* temp= head;
	int nodecount=1;
	while(temp->!=nullptr && nodecount<=n-1){
		temp=temp->next;
	}
	Node* temp2= temp->next;
	cout<< "delete : "<< temp2->data<<endl;
	 temp->next = temp->next->next;
	 delete temp2;


}