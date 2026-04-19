#include <iostream>
using namespace std;

int main(){
    int n,A[100];
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>A[i];

    // Linear
    for(int i=0;i<n;i++)
        if(A[i]==77)
            cout<<"Linear Found at "<<i<<endl;

    // Binary (sorted)
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==77){
            cout<<"Binary Found at "<<mid;
            break;
        }
        else if(A[mid]<77) low=mid+1;
        else high=mid-1;
    }
}