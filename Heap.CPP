#include <iostream>
using namespace std;

#define MAX 100

int heapArr[MAX];
int size = 0;

// Heapify Up (for insertion)
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heapArr[parent] < heapArr[i]) {
            swap(heapArr[parent], heapArr[i]);
            i = parent;
        } else break;
    }
}

// Heapify Down (for deletion)
void heapifyDown(int i) {
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = left;

        if (right < size && heapArr[right] > heapArr[left])
            largest = right;

        if (heapArr[i] < heapArr[largest]) {
            swap(heapArr[i], heapArr[largest]);
            i = largest;
        } else break;
    }
}

// Insert into Heap
void insertHeap(int value) {
    if (size == MAX) {
        cout << "Heap Overflow\n";
        return;
    }
    heapArr[size] = value;
    heapifyUp(size);
    size++;
}

// Delete root from Heap
void deleteHeap() {
    if (size == 0) {
        cout << "Heap Underflow\n";
        return;
    }
    cout << "Deleted element (root): " << heapArr[0] << endl;
    heapArr[0] = heapArr[size - 1];
    size--;
    heapifyDown(0);
}

// Display Heap
void displayHeap() {
    cout << "Heap elements: ";
    for (int i = 0; i < size; i++)
        cout << heapArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertHeap(value);
                break;
            case 2:
                deleteHeap();
                break;
            case 3:
                displayHeap();
                break;
        }
    } while (choice != 4);

    return 0;
}