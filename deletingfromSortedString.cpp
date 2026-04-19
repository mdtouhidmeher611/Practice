#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n,pos=-1;
    char A[100][50];
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=0;i<n;i++){
        if(strcmp(A[i],"Karim")==0){
            pos=i;
            break;
        }
    }

    for(int i=pos;i<n-1;i++)
        strcpy(A[i],A[i+1]);

    n--;

    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;
}