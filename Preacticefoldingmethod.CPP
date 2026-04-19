#include <iostream>
using namespace std;

#define SIZE 11 // Prime number for table size

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) table[i] = -1; // -1 indicates empty
    }

    // Folding Method Hash Function
    int hashFunction(int key) {
        int sum = 0;
        while (key > 0) {
            sum += key % 100; // Take 2 digits at a time
            key /= 100;
        }
        return sum % SIZE;
    }

    // Insert using Linear Probing
    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        // Linear Probing: index = (index + 1) % SIZE
        while (table[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == originalIndex) {
                cout << "Table Full!" << endl;
                return;
            }
        }
        table[index] = key;
    }

    void search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        cout << "Key not found." << endl;
    }
};

int main() {
    HashTable ht;
    ht.insert(1234); // 12 + 34 = 46 % 11 = 2
    ht.insert(5678); // 56 + 78 = 134 % 11 = 2 (Collision!)
    ht.search(5678);
    return 0;
}