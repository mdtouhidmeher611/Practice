#include <iostream>
using namespace std;

#define MAX 20

int main() {
    int m;
    int A[MAX][MAX], P[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> m;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            P[i][j] = A[i][j]; // Initialize Path matrix
        }
    }

    // Warshall's Algorithm
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
            }
        }
    }

    cout << "\nPath Matrix (Reachability Matrix):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}