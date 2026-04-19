#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    char A[100][50];
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(strcmp(A[j],A[j+1])>0){
                char t[50];
                strcpy(t,A[j]);
                strcpy(A[j],A[j+1]);
                strcpy(A[j+1],t);
            }

    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;
}