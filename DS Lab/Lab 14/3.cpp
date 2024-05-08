#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int tableSize = 10;
    vector<pair<int, int>> table;
    vector<bool> occupied;

    int hashFunction1(int key) {
        return key % tableSize;
    }

    int hashFunction2(int key) {
        return 7 - (key % 7);
    }

public:
    HashTable() : table(tableSize), occupied(tableSize, false) {}

    int doubleHash(int key, int attempt) {
        return (hashFunction1(key) + attempt * hashFunction2(key)) % tableSize;
    }

    void insert(int key, int value) {
        int attempt = 0;
        int index = doubleHash(key, attempt);
        while (occupied[index]) {
            attempt++;
            index = doubleHash(key, attempt);
        }
        table[index] = {key, value};
        occupied[index] = true;
    }

    int search(int key) {
        int attempt = 0;
        int index = doubleHash(key, attempt);
        while (attempt < tableSize && occupied[index]) {
            if (table[index].first == key) {
                return table[index].second;
            }
            attempt++;
            index = doubleHash(key, attempt);
        }
        return -1;
    }

    void remove(int key) {
        int attempt = 0;
        int index = doubleHash(key, attempt);
        while (attempt < tableSize && occupied[index]) {
            if (table[index].first == key) {
                occupied[index] = false;
                return;
            }
            attempt++;
            index = doubleHash(key, attempt);
        }
    }
};

int main() {
    HashTable hashTable;
    hashTable.insert(42, 420);
    hashTable.insert(19, 190);
    hashTable.insert(10, 100);
    hashTable.insert(2, 20);

    int searchKey = 10;
    int result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "Element found at key " << searchKey << ": " << result << endl;
    } else {
        cout << "Element not found at key " << searchKey << endl;
    }

    int deleteKey = 19;
    hashTable.remove(deleteKey);
    cout << "Element at key " << deleteKey << " deleted." << endl;

    return 0;
}
