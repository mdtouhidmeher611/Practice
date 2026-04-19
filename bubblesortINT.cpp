#include <iostream>
using namespace std;

int main(){
    int n,A[100];
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(A[j]>A[j+1]){
                int t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }

    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}