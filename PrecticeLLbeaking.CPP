#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void insert(Node*& head, int newdata){
	Node* newNode = new Node();
	newNode->data= newdata;
	newNode->next= nullptr;

	if(head==nullptr){
		head=newNode;
		return;
	}
	Node* temp= head;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next=newNode;
}

void print(Node* head){
	Node* temp= head;
	cout <<" The main list : { ";
	while(temp !=nullptr){
		cout << temp->data <<"  ";
		temp=temp->next;
	}
	cout <<"}";
}
void print2(Node* head, int n){
	Node* temp= head;
	int total = n;
	int i=1;
	cout << "\n 1st half of the list: { ";
	while(i<=((total/2) + 1 )){
		cout<< temp->data << "  ";
		temp=temp->next;
		i++;
	}
	cout << "}"; 
	cout << " \n2nd half of the list : { ";
	while(temp!=nullptr){
		cout << temp->data <<"  ";
		temp=temp->next;
	}
	cout<<"}";
}

int main(){
	Node* head;
	head=nullptr;
	int n;
	int value;
	cout <<"enter the number of values in linked list: ";
	cin >> n;
	for(int i=0; i<n ;i++){
		cin >>value ;
		insert(head,value) ;
	}
	print(head);
	print2(head,n);
	return 0;
}