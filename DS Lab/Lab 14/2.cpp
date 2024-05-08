#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int tableSize = 10;
    vector<pair<int, int>> table;
    vector<bool> occupied;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() : table(tableSize), occupied(tableSize, false) {}

    void insert(int key, int value) {
        int index = hashFunction(key);
        while (occupied[index]) {
            index = (index + 1) % tableSize;
        }
        table[index] = {key, value};
        occupied[index] = true;
    }

    int search(int key) {
        int index = hashFunction(key);
        int probes = 0;
        while (probes < tableSize && occupied[index]) {
            if (table[index].first == key) {
                return table[index].second;
            }
            index = (index + 1) % tableSize;
            probes++;
        }
        return -1;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int probes = 0;
        while (probes < tableSize && occupied[index]) {
            if (table[index].first == key) {
                occupied[index] = false;
                return;
            }
            index = (index + 1) % tableSize;
            probes++;
        }
    }
};

int main() {
    HashTable hashTable;
    hashTable.insert(43, 430);
    hashTable.insert(145, 1450);
    hashTable.insert(72, 720);
    hashTable.insert(23, 230);
    hashTable.insert(99, 990);
    hashTable.insert(19, 190);
    hashTable.insert(82, 820);

    int searchKey = 23;
    int result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "Element found at key " << searchKey << ": " << result << endl;
    } else {
        cout << "Element not found at key " << searchKey << endl;
    }

    int deleteKey = 99;
    hashTable.remove(deleteKey);
    cout << "Element at key " << deleteKey << " deleted." << endl;

    return 0;
}
