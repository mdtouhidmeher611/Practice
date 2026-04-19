#include <iostream>
using namespace std;

int main(){
    int n,A[100],item=54;
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];

    int i=n-1;
    while(i>=0 && A[i]>item){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=item;
    n++;

    for(int i=0;i<n;i++) cout<<A[i]<<" ";
}