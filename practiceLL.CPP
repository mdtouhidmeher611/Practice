#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data ;
	Node* next;
};

int main(){
	Node* head  = nullptr;
	Node* second  = nullptr;
	Node* third  = nullptr;


	head = new Node();
	second = new Node();
	third = new Node();

	head->data= 10;
	head->next = second;

	second->data= 20;
	second->next=third;

	third->data= 30;
	third->next= nullptr;

	//printing the list
	Node* temp = head;
	while(temp!=nullptr){
		cout << temp->data << "-->";
		temp = temp->next;
	}
	cout<< "NULL" << endl;

	return 0;
}