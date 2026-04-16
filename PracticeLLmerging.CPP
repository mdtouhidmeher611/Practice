#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};
void merge(Node* head1, Node* head2){
	if(head1==nullptr)	{
		head1=head2;
		return;
	}
	Node* temp = head1;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next=head2;
}

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
	cout <<" The merged list : { ";
	while(temp !=nullptr){
		cout << temp->data <<"  ";
		temp=temp->next;
	}
	cout <<"}";
}
int main(){
	Node* head1;
	Node* head2;
	head1=nullptr;
	head2=nullptr;

	int n1,n2;
	int value;
	cout <<"enter the number of values in linked list1: ";
	cin >> n1;
	for(int i=0; i<n1 ;i++){
		cin >>value ;
		insert(head1,value) ;
	}
	//print(head1);
	cout <<"enter the number of values in linked list2: ";
	cin >> n2;
	for(int i=0; i<n2 ;i++){
		cin >>value ;
		insert(head2,value) ;
	}
	//print(head2);

	merge(head1,head2);
	print(head1);
	return 0;
}