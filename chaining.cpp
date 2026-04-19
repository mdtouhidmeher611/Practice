#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* table[11];

int hashFunc(int key){
    return key % 11;
}

int main(){
    int data[9] = {54,26,93,17,77,31,44,55,20};

    for(int i=0;i<11;i++)
        table[i] = NULL;

    // Insert
    for(int i=0;i<9;i++){
        int key = data[i];
        int index = hashFunc(key);

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Display
    for(int i=0;i<11;i++){
        Node* temp = table[i];
        cout<<i<<" -> ";
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}