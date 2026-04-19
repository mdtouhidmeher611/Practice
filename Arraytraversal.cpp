#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int A[100];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    int max=A[0], min=A[0], sum=0;
    for(int i=0;i<n;i++){
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
        sum+=A[i];
        cout << "Sin("<<A[i]<<") = " << sin(A[i]) << endl;
    }

    cout << "Max="<<max<<"\nMin="<<min<<"\nTotal="<<sum;
    cout << "\nAverage="<<(float)sum/n;
}