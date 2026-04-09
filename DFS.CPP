#include <iostream>
using namespace std;

#define MAX 20

// Node for adjacency list
struct Node {
    int vertex;
    Node* next;
};

Node* adjList[MAX];
bool visited[MAX];

// Create new node
Node* createNode(int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// DFS Traversal (recursive)
void DFS(int v) {
    visited[v] = true;
    cout << "V" << v << " ";

    Node* temp = adjList[v];
    while (temp != NULL) {
        int adjV = temp->vertex;
        if (!visited[adjV]) {
            DFS(adjV);
        }
        temp = temp->next;
    }
}

int main() {
    int m, e, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        adjList[i] = NULL;
        visited[i] = false;
    }

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        addEdge(u, v);
    }

    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}