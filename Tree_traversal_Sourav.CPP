#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createnode(int data){
	Node* n = new Node();
	n->data =  data;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

void preorder(Node* root){
	if(root!=nullptr){
	cout<<root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
}

void inorder(Node* root){
	if(root!=nullptr){
	inorder(root->left);
	cout<< root->data <<" ";
	inorder(root->right);
}
}

void postorder(Node* root){
	if(root!=nullptr){
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
}
int main(){
	Node* p0 = createnode(13);
	Node* p1 = createnode(4);
	Node* p2 = createnode(12);
	Node* p3 = createnode(16);
	Node* p4 = createnode(17);
	Node* p5 = createnode(18);
	Node* p6 = createnode(119);

	p0->left = p1;
	p0->right = p2;
	p1->left = p3;
	p1->right = p4;
	p2->left = p5;
	p2->right = p6;

	cout << "Preorder Traversal : ";preorder(p0);cout<<endl;
	cout<<"Inorder traversal : ";inorder(p0);cout<<endl;
	cout<<"Postorder traversal : ";postorder(p0);cout << endl;

}