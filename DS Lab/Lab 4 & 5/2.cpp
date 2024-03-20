#include<iostream>
using namespace std;

class linked_list {
public:
    string key;
    string data;
    linked_list *next;

    // Constructor
    linked_list() {
        // key = 0;
        // data = 0;
        next = nullptr;
    }

    // Parameterized Constructor
    linked_list(int k, int d) {
        key = k;
        data = d;
        next = nullptr;
    }

    //push
    void push(linked_list **head, int ndata) {
        linked_list *nnode = new linked_list();
        nnode->data = ndata;
        nnode->next = *head;
        *head = nnode;
    }

    //Print Linked List Function
    void printList(linked_list *node) {
        while (node != nullptr) {
            cout << " " << node->data;
            node = node->next;
        }
    }

    linked_list* reverseList(linked_list* head) {
        linked_list *prev = nullptr, *next = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(linked_list* head) {
        if (!head || !head->next){
            return true;
        }
        linked_list *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        linked_list* secondHalf = reverseList(slow->next);
        while (secondHalf) {
            if (head->data != secondHalf->data)
                return false;
            head = head->next;
            secondHalf = secondHalf->next;
        }

        return true;        
    }
};

int main() {
    linked_list *head = nullptr;

    linked_list ll;
    ll.push(&head, 'p');
    ll.push(&head, 'a');
    ll.push(&head, 'n');
    ll.push(&head, 'a');
    ll.push(&head, 'p');
    ll.printList(head);

    int palindrome=ll.isPalindrome(head);
    if(palindrome){
        cout << endl << "The given linked list is palindrome" << endl;
    }
    else{
        cout << endl << "The givexn linked list is not palindrome" << endl;
    }
    return 0;
}