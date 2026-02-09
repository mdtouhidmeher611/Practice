#include <iostream>
using namespace std;

int main() {
    int m, n, key, searchKey;
    cout << "Enter hash table size (prime): ";
    cin >> m;

    int hashTable[m];
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> key;
        int index = key % m;

        while (hashTable[index] != -1) {
            index = (index + 1) % m;
        }
        hashTable[index] = key;
    }

    cout << "Enter element to search: ";
    cin >> searchKey;

    int index = searchKey % m;
    int start = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == searchKey) {
            cout << "Element found at index " << index << endl;
            return 0;
        }
        index = (index + 1) % m;
        if (index == start)
            break;
    }

    cout << "Element not found\n";
    return 0;
}
