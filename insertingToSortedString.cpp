#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    char A[100][50], item[]="Rahim";
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];

    int i=n-1;
    while(i>=0 && strcmp(A[i],item)>0){
        strcpy(A[i+1],A[i]);
        i--;
    }
    strcpy(A[i+1],item);
    n++;

    for(int i=0;i<n;i++) cout<<A[i]<<endl;
}