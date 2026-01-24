#include<bits/stdc++.h>
using namespace std ;
struct node{
	int data ;
	node* next;
};
void printlist(node* head){
	node* temp = head;
	cout << "The Linked List: " ;
	while(temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << "\n" ;
}
void insertatbegining(node*& head , int newData){
	node* newNode = new node();
	newNode->data = newData;
	newNode->next = head;
	head= newNode;
}
void insertatend(node*& head, int newData){
	node* newNode = new node();
	newNode->data = newData;
	newNode->next= nullptr;
}

int main(){
	node* head = nullptr;
	int n;
	int data;
	int choice;
	cout << "linked list menu : "<<"\n";
	//cout<< "HOW MANY NODES DO YOU NEED IN LINKED LIST : ";
	//cin >>n;
	do{
		cout << "\n1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        //cout << "3. Insert After a Specific Value\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        //cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
        	case 1:
        		cout <<"Enter the value to be added at begining : ";
        		cin >> data;
        		insertatbegining(head,data);
        		break;
        	case 2:
        		cout <<"Enter the value to be added at end : ";
        		cin >> data;
        		insertatend(head,data);
        		break;
        	case 3:
        		printlist(head);
        		break;
        	case 4:
        		cout<<"Exiting program..........";
        		break;
        	default:
        		cout<<"Invalid choice :( ";
        		break;
        }
	 }while(choice!=4);
	return 0;

}