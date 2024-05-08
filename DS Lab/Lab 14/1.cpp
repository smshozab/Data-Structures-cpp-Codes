#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int tableSize = 10;
    vector<Node*> table;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() : table(tableSize, nullptr) {}

    void insert(int key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    ~HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable hashTable;
    hashTable.insert(24, 240);
    hashTable.insert(52, 520);
    hashTable.insert(91, 910);
    hashTable.insert(67, 670);
    hashTable.insert(48, 480);
    hashTable.insert(89, 890);

    int searchKey = 67;
    int result = hashTable.search(searchKey);
    if (result != -1) {
        cout << "Element found at key " << searchKey << ": " << result << endl;
    } else {
        cout << "Element not found at key " << searchKey << endl;
    }

    int deleteKey = 91;
    hashTable.remove(deleteKey);
    cout << "Element at key " << deleteKey << " deleted." << endl;

    return 0;
}
