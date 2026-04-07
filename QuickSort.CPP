#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = arr[high], i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);

    int pi = i + 1;
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int main() {
    int arr[10];
    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) cin >> arr[i];

    quickSort(arr, 0, 9);

    cout << "Sorted array:\n";
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
}