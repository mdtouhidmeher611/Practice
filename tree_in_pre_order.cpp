#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* n = new Node;
    n->data = data;
    n->left = NULL;
    n->right= NULL;
    return n;
}

void preOrder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root){
     if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Node* p0 = createNode(13);
    Node* p1 = createNode(4);
    Node* p2 = createNode(12);
    Node* p3 = createNode(16);
    Node* p4 = createNode(17);
    Node* p5 = createNode(18);
    Node* p6 = createNode(19);

    p0->left=p1;
    p0->right=p2;

    p1->left=p3;
    p1->right=p4;

    p2->left=p5;
    p2->right=p6;

    preOrder(p0);  cout<<endl;
    inOrder(p0);   cout<<endl;
    postOrder(p0);

}