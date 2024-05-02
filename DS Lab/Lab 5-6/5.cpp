#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to add a new node at the end of the linked list
    void addAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to add a new node at the start of the linked list
    void addAtStart(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Function to add a new node at a certain position
    void addAtPosition(int val, int position) {
        if (position <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 1) {
            addAtStart(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node at a certain position
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (position <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* temp = head;
        if (position == 1) {
            while (temp->next != head) {
                temp = temp->next;
            }
            if (temp == head) {
                delete head;
                head = nullptr;
            } else {
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
        } else {
            Node* prev = nullptr;
            for (int i = 1; i < position && temp->next != head; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == head) {
                cout << "Position out of bounds" << endl;
                return;
            }
            prev->next = temp->next;
            delete temp;
        }
    }

    // Function to update the data of a node at a certain position
    void updateDataAtPosition(int val, int position) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (position <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp == head) {
            cout << "Position out of bounds" << endl;
            return;
        }
        temp->data = val;
    }

    // Function to traverse & print the circular linked list
    void traverseAndPrint() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.addAtEnd(1);
    list.addAtEnd(2);
    list.addAtEnd(3);
    list.addAtStart(0);
    list.addAtPosition(4, 4);
    list.traverseAndPrint();

    list.deleteAtPosition(3);
    list.updateDataAtPosition(10, 2);
    list.traverseAndPrint();

    return 0;
}
