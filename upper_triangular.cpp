#include <iostream>
using namespace std;

int main(){
    int n, A[10][10], B[100], k = 0;

    cout << "Enter order of matrix: ";
    cin >> n;

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    // Store Upper Triangular Elements (including diagonal) into 1D array
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            B[k] = A[i][j];
            k++;
        }
    }

    cout << "\nUpper Triangular stored in 1D array:\n";
    for(int i = 0; i < k; i++)
        cout << B[i] << " ";

    // Locate A[3][2] in B (0-based index)
    int row = 3, col = 2;

    if(col < row){
        cout << "\nA[3][2] is not in upper triangular part.";
    } else {
        int index = row * n - (row * (row - 1)) / 2 + (col - row);
        cout << "\nIndex of A[3][2] in B: " << index;
    }

    return 0;
}