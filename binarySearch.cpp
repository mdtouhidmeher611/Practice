#include <iostream>
using namespace std;

int main() {
    int n, A[100], item;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter item to search: ";
    cin >> item;

    int low = 0, high = n - 1, mid;
    int found = 0;

    while(low <= high) {
        mid = (low + high) / 2;

        if(A[mid] == item) {
            cout << "Item found at position: " << mid;
            found = 1;
            break;
        }
        else if(A[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found == 0)
        cout << "Item not found.";

    return 0;
}