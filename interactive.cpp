#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    double arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double maxVal = arr[0], minVal = arr[0], sum = 0;

    cout << "\nSine values:\n";
    for(int i = 0; i < n; i++) {
        if(arr[i] > maxVal) maxVal = arr[i];
        if(arr[i] < minVal) minVal = arr[i];
        sum += arr[i];
        cout << "sin(" << arr[i] << ") = " << sin(arr[i]) << endl;
    }

    double average = sum / n;

    cout << "\nMaximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;
    cout << "Total: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}