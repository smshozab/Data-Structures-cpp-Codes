#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Add a new node at the end of the linked list
    void append(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Add a new node at the start of the linked list
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Add a new node at a certain position
    void insertAt(int position, int value) {
        if (position < 0 || position > size)
            return;

        if (position == 0) {
            prepend(value);
        } else if (position == size) {
            append(value);
        } else {
            Node* newNode = new Node(value);
            Node* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }

    // Delete last node
    void deleteLast() {
        if (size == 0)
            return;

        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = tail->prev;
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }
        size--;
    }

    // Delete a node at a certain position
    void deleteAt(int position) {
        if (position < 0 || position >= size)
            return;

        if (position == 0) {
            Node* temp = head->next;
            delete head;
            head = temp;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
        } else if (position == size - 1) {
            deleteLast();
        } else {
            Node* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        size--;
    }

    // Update the data of a node at a certain position
    void updateAt(int position, int newValue) {
        if (position < 0 || position >= size)
            return;

        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        current->data = newValue;
    }

    // Traverse & print
    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Bubble Sort for sorting the linked list
    void sort() {
        if (size <= 1)
            return;

        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = head; j->next != nullptr; j = j->next) {
                if (j->data > j->next->data) {
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
            }
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.append(1);
    dll.append(3);
    dll.append(2);
    dll.append(5);

    cout << "Original list: ";
    dll.traverse();

    dll.prepend(0);
    cout << "List after prepend: ";
    dll.traverse();

    dll.insertAt(3, 4);
    cout << "List after inserting 4 at position 3: ";
    dll.traverse();

    dll.deleteLast();
    cout << "List after deleting last node: ";
    dll.traverse();

    dll.deleteAt(1);
    cout << "List after deleting at position 1: ";
    dll.traverse();

    dll.updateAt(2, 6);
    cout << "List after updating at position 2: ";
    dll.traverse();

    dll.sort();
    cout << "Sorted list: ";
    dll.traverse();

    return 0;
}
