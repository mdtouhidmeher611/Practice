#include <iostream>
using namespace std;

#define MAX 20

int m;
int A[MAX][MAX], powerMat[MAX][MAX], temp[MAX][MAX], Br[MAX][MAX];

// Matrix multiplication
void multiply(int X[MAX][MAX], int Y[MAX][MAX], int Z[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            Z[i][j] = 0;
            for (int k = 0; k < m; k++) {
                Z[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
}

// Copy matrix
void copyMatrix(int X[MAX][MAX], int Y[MAX][MAX]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            Y[i][j] = X[i][j];
}

// Add matrix to Br
void addToBr(int X[MAX][MAX]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            Br[i][j] += X[i][j];
}

// Print matrix
void printMatrix(int X[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            cout << X[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> m;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    // Initialize Br = A
    copyMatrix(A, Br);
    copyMatrix(A, powerMat);

    // Compute Br = A + A^2 + ... + A^m
    for (int p = 2; p <= m; p++) {
        multiply(powerMat, A, temp);
        copyMatrix(temp, powerMat);
        addToBr(powerMat);
    }

    cout << "\nMatrix Br:\n";
    printMatrix(Br);

    // Path Matrix
    int P[MAX][MAX];
    cout << "\nPath Matrix P:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            P[i][j] = (Br[i][j] > 0) ? 1 : 0;
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    // Check Strong Connectivity
    bool stronglyConnected = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j && P[i][j] == 0) {
                stronglyConnected = false;
                break;
            }
        }
    }

    if (stronglyConnected)
        cout << "\nThe graph is Strongly Connected.\n";
    else
        cout << "\nThe graph is NOT Strongly Connected.\n";

    return 0;
}