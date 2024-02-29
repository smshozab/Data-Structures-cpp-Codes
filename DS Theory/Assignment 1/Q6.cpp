#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {

public:
    ListNode *head;
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the linked list
    void insert(int val) {
        if (!head) {
            head = new ListNode(val);
        } else {
            ListNode *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new ListNode(val);
        }
    }

    // Function to split the linked list into sublists with sum equal to n
    void splitLinkedList(int n) {
        ListNode *curr = head;

        while (curr) {
            int sum = 0;
            ListNode *sublistHead = nullptr;
            ListNode *prev = nullptr;
            ListNode *sublistEnd = nullptr;

            ListNode *start = curr;

            while (curr && sum != n) {
                sum += curr->val;
                if (sum <= n) {
                    if (!sublistHead) {
                        sublistHead = curr;
                    }
                    prev = curr;
                    sublistEnd = curr;
                    curr = curr->next;
                } else {
                    sum -= curr->val;
                    break;
                }
            }

            if (sum == n) {
                if (prev) {
                    prev->next = nullptr;
                }
                cout << "Sublist with sum " << n << ": ";
                printList(sublistHead);
                if (curr) {
                    start = curr->next;
                }
            } else {
                if (start) {
                    curr = start->next;
                } else {
                    curr = nullptr;
                }
            }

            if (sublistEnd) {
                sublistEnd->next = curr;
            }
        }
    }

    // Utility function to print the linked list
    void printList(ListNode *head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(5);
    list.insert(4);
    list.insert(11);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout << "Original List: ";
    list.printList(list.head);

    int targetSum = 16;
    cout << "Sublists with sum equal to " << targetSum << ":\n";
    list.splitLinkedList(targetSum);

    return 0;
}
