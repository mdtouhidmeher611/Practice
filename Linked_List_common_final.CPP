#include <bits/stdc++.h>
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

void common(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        cout << "One or both lists are empty. No common nodes.\n";
        return;
    }

    bool found = false;
    cout << "Common nodes: ";

    Node* temp1 = head1;
    while (temp1 != nullptr) {
        Node* temp2 = head2;
        while (temp2 != nullptr) {
            if (temp1->data == temp2->data) {
                cout << temp1->data << " ";
                found = true;
                // Once a match is found for temp1, break inner loop 
                // to avoid printing the same element multiple times 
                // if list2 has duplicates.
                break; 
            }
            temp2 = temp2->next; // Move to the next node in list2
        }
        temp1 = temp1->next; // Move to the next node in list1
    }

    if (!found) {
        cout << "None";
    }
    cout << endl;
}
int main(){
	Node* head1 =nullptr;
	Node* head2 =nullptr;

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

	common(head1,head2);

	return 0;
}