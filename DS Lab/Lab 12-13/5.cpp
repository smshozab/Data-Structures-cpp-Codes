#include <iostream>
using namespace std;

struct Node {
    int rollNumber;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int rollNumber) {
    Node* newNode = new Node();
    newNode->rollNumber = rollNumber;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertNode(Node* root, int rollNumber) {
    if (root == nullptr) return createNode(rollNumber);

    if (rollNumber < root->rollNumber)
        root->left = insertNode(root->left, rollNumber);
    else if (rollNumber > root->rollNumber)
        root->right = insertNode(root->right, rollNumber);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && rollNumber < root->left->rollNumber)
        return leftRotate(root);

    return root;
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << "Student with roll number " << root->rollNumber << endl;
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 2);
    root = insertNode(root, 30);
    root = insertNode(root, 38);
    root = insertNode(root, 78);
    root = insertNode(root, 92);

    root = insertNode(root, 15);
    cout << "Inorder traversal of AVL tree:" << endl;
    inorderTraversal(root);

    return 0;
}
