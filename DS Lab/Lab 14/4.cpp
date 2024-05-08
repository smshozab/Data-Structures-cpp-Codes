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
    hashTable.insert(20, 200);
    hashTable.insert(34, 340);
    hashTable.insert(45, 450);
    hashTable.insert(70, 700);
    hashTable.insert(56, 560);

    int searchKey = 45;
    int result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "Element found at key " << searchKey << ": " << result << endl;
    } else {
        cout << "Element not found at key " << searchKey << endl;
    }

    int deleteKey = 34;
    hashTable.remove(deleteKey);
    cout << "Element at key " << deleteKey << " deleted." << endl;

    return 0;
}
