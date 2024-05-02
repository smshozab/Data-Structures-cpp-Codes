#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = height(node->left) - height(node->right);
    if (balance > 1 && key < node->left->key)
        return leftRotate(node);
    return node;
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    for (int key : elements) {
        root = insert(root, key);
    }
    inOrder(root);
    cout << endl;
    root = insert(root, 55);
    root = leftRotate(root);
    inOrder(root);
    cout << endl;
    return 0;
}
