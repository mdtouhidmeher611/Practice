#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* root = NULL;

// Insert and report location if duplicate
Node* insertBST(Node* node, int key, string path, bool &found) {
    if (node == NULL) {
        cout << "Inserted at location: " << path << endl;
        return new Node(key);
    }

    if (key == node->data) {
        cout << "Element already exists at location: " << path << endl;
        found = true;
        return node;
    }
    else if (key < node->data) {
        node->left = insertBST(node->left, key, path + " -> Left", found);
    }
    else {
        node->right = insertBST(node->right, key, path + " -> Right", found);
    }

    return node;
}

int main() {
    int n, value;

    cout << "How many elements to insert initially? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        bool found = false;
        root = insertBST(root, value, "Root", found);
    }

    cout << "\nInsert one more element to check duplicate/location: ";
    cin >> value;

    bool found = false;
    root = insertBST(root, value, "Root", found);

    return 0;
}