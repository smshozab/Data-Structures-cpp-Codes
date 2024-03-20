#include<iostream>
using namespace std;

class linked_list {
public:
    int key;
    int data;
    linked_list *next;

    // Constructor
    linked_list() {
        key = 0;
        data = 0;
        next = NULL;
    }

    // Parameterized Constructor
    linked_list(int k, int d) {
        key = k;
        data = d;
    }

    void push(linked_list **head, int ndata) {
        linked_list *nnode = new linked_list();
        nnode->data = ndata;
        nnode->next = *head;
        *head = nnode;
    }

    bool hasCycle(linked_list *head) {
        linked_list* slow=head;
        linked_list* fast=head;

        if (head==nullptr || head->next==nullptr) {
            return false;
        }

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
            return false;
    }
};

int main(){
    linked_list *head = NULL;

    linked_list ll;
    ll.push(&head, 5);
    ll.push(&head, 4);
    ll.push(&head, 3);
    ll.push(&head, 2);
    ll.push(&head, 1);
    linked_list *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head->next->next;

    if (ll.hasCycle(head)) {
        cout << "The linked list contains a cycle.\n";
    } else {
        cout << "The linked list does not contain a cycle.\n";
    }

    return 0;
}