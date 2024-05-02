#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Insert a node into the binary search tree
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// In-order traversal of the binary search tree
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Pre-order traversal of the binary search tree
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal of the binary search tree
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "In-order traversal of the tree: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order traversal of the tree: ";
    preorder(root);
    cout << endl;

    cout << "Post-order traversal of the tree: ";
    postorder(root);
    cout << endl;

    return 0;
}
