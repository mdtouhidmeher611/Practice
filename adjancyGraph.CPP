#include <iostream>
using namespace std;

#define MAX 20

int A[MAX][MAX], temp[MAX][MAX], result[MAX][MAX];
int m;

// Matrix multiplication: X * Y -> Z
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

    // (a) Adjacent vertices
    cout << "\nAdjacent vertices:\n";
    for (int i = 0; i < m; i++) {
        cout << "Adjacent of V" << i+1 << ": ";
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1)
                cout << "V" << j+1 << " ";
        }
        cout << endl;
    }

    // Compute A^2
    multiply(A, A, result);
    cout << "\nMatrix A^2 (Paths of length 2):\n";
    printMatrix(result);

    // Compute A^3 = A^2 * A
    copyMatrix(result, temp);
    multiply(temp, A, result);
    cout << "\nMatrix A^3 (Paths of length 3):\n";
    printMatrix(result);

    // Compute A^4 = A^3 * A
    copyMatrix(result, temp);
    multiply(temp, A, result);
    cout << "\nMatrix A^4 (Paths of length 4):\n";
    printMatrix(result);

    return 0;
}