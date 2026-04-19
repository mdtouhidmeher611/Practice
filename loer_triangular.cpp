#include <iostream>
using namespace std;

int main(){
    int n,A[10][10],B[100],k=0;
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            B[k++]=A[i][j];

    int index=(3*(3+1))/2+2;
    cout<<"Index of A[3][2] in B: "<<index;
}