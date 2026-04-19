#include <iostream>
using namespace std;

int main(){
    int r,c,A[10][10],B[100],k=0;
    cin>>r>>c;

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>A[i][j];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            B[k++]=A[i][j];

    for(int i=6;i<9;i++)
        cout<<B[i]<<" ";
}