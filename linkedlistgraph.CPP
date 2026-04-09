#include <iostream>
using namespace std;

#define MAX 20

// Node for adjacency list
struct Node {
    int vertex;
    Node* next;
};

// Array of adjacency lists
Node* adjList[MAX];

// Create a new node
Node* createNode(int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to graph (undirected)
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // For undirected graph, add reverse edge
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Display graph
void displayGraph(int m) {
    for (int i = 0; i < m; i++) {
        cout << "Adjacent of V" << i << ": ";
        Node* temp = adjList[i];
        while (temp != NULL) {
            cout << "V" << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int m, e, u, v;

    cout << "Enter number of vertices: ";
    cin >> m;

    // Initialize adjacency list
    for (int i = 0; i < m; i++)
        adjList[i] = NULL;

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(u, v);
    }

    cout << "\nGraph Representation (Adjacency List):\n";
    displayGraph(m);

    return 0;
}