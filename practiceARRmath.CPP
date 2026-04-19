#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Input dimensions for Matrix A
    cout << "Enter rows and columns for Matrix A: ";
    cin >> r1 >> c1;

    // Input dimensions for Matrix B
    cout << "Enter rows and columns for Matrix B: ";
    cin >> r2 >> c2;

    int A[r1][c1], B[r1][c1]; 

    // Input elements for Matrix A
    cout << "Enter elements for Matrix A:" << endl;
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    // Input elements for Matrix B
    cout << "Enter elements for Matrix B:" << endl;
    for(int i = 0; i < r2; i++) {
        for(int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    // --- ADDITION ---
    if (r1 == r2 && c1 == c2) {
        cout << "\nAddition Result:" << endl;
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c1; j++) {
                cout << A[i][j] + B[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nAddition not possible (Dimensions must match)." << endl;
    }

    //---Subtraction---//

    if (r1==r2 && c1== c2){
    	cout<<"\n subtraction result :\n";
    	for(int i=0;i<r1;i++){
    		for(int j=0;j<c1;j++){
    			cout << A[i][j] -B[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
    else{
    	cout << " \n subtraction not possible (dimensions must be same)." <<endl;

    }

    	//----multiplication----//
    int prod[r1][c2];
    if(c1==r2){
    	cout << "\n Multiplication result : \n";
   		for(int i = 0; i < r1; i++) {
           	for(int j = 0; j < c2; j++) {
         	    for(int k = 0; k < c1; k++) {
                	prod[i][j] += A[i][k] * B[k][j];
                }
                cout << prod[i][j] << " ";
            }
           	cout << endl;
        }
    }
    else{
   		cout<<"\n Multiplication not possible (number of colums of 1st matrix must be equal to the number of columns of second matrix)\n";
   	}
    return 0;
}