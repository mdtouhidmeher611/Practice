#include <iostream>
using namespace std;

int main(){
    int r,c,A[10][10],B[10][10],C[10][10];
    cin>>r>>c;

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>A[i][j];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>B[i][j];

    // Add & Sub
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<A[i][j]+B[i][j]<<" ";
        }
        cout<<endl;
    }

    // Multiply
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            C[i][j]=0;
            for(int k=0;k<c;k++)
                C[i][j]+=A[i][k]*B[k][j];
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}