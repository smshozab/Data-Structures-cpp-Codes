#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

Node* concatenateLists(Node* L, Node* M) {
    if (L == nullptr) {
        return M;
    }
    if (M == nullptr) {
        return L;
    }

    Node* L_tail = L;
    while (L_tail->next != nullptr) {
        L_tail = L_tail->next;
    }
    L_tail->next = M;
    M->prev = L_tail;

    return L;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* L_head = new Node(1);
    L_head->next = new Node(2);
    L_head->next->prev = L_head;
    Node* M_head = new Node(3);
    M_head->next = new Node(4);
    M_head->next->prev = M_head;

    cout << "Original L list: ";
    printList(L_head);

    cout << "Original M list: ";
    printList(M_head);

    Node* concatenated_list = concatenateLists(L_head, M_head);
    cout << "Concatenated list: ";
    printList(concatenated_list);
    return 0;
}