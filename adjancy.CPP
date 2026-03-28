#include <iostream>
using namespace std;

void multiply(int A[20][20], int B[20][20], int C[20][20], int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            C[i][j]=0;
            for(int k=0;k<n;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
}

int main() {
    int n, A[20][20], A2[20][20], A3[20][20], A4[20][20];

    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];

    // Adjacent vertices
    for(int i=0;i<n;i++) {
        cout<<"Adjacent of V"<<i+1<<": ";
        for(int j=0;j<n;j++)
            if(A[i][j]==1) cout<<"V"<<j+1<<" ";
        cout<<endl;
    }

    multiply(A,A,A2,n);
    multiply(A2,A,A3,n);
    multiply(A3,A,A4,n);

    cout<<"\nPaths of length 2:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<A2[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nPaths of length 3:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<A3[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nPaths of length 4:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<A4[i][j]<<" ";
        cout<<endl;
    }
}