#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct BinaryTree {
    int* nodes;
    int size;
    int capacity;

    BinaryTree(int maxNodes) : size(0), capacity(maxNodes) {
        nodes = new int[capacity];
    }

    ~BinaryTree() {
        delete[] nodes;
    }

    void insert(int val) {
        if (size < capacity) {
            nodes[size++] = val;
        } else {
            cout << "Binary tree is full." << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
};

struct CompleteBinaryTree {
    int* nodes;
    int size;
    int capacity;

    CompleteBinaryTree(int maxNodes) : size(0), capacity(maxNodes) {
        nodes = new int[capacity];
    }

    ~CompleteBinaryTree() {
        delete[] nodes;
    }

    void insert(int val) {
        if (size < capacity) {
            nodes[size++] = val;
        } else {
            cout << "Complete binary tree is full." << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree binaryTree(10);
    binaryTree.insert(1);
    binaryTree.insert(9);
    binaryTree.insert(4);
    binaryTree.insert(8);
    binaryTree.insert(1);
    binaryTree.insert(2);
    binaryTree.insert(7);
    binaryTree.display();

    CompleteBinaryTree completeBinaryTree(10);
    completeBinaryTree.insert(1);
    completeBinaryTree.insert(2);
    completeBinaryTree.insert(3);
    completeBinaryTree.insert(4);
    completeBinaryTree.insert(5);
    completeBinaryTree.display();

    return 0;
}