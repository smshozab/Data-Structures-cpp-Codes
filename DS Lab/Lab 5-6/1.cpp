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

    //push
    void push(linked_list **head, int ndata) {
        linked_list *nnode = new linked_list();
        nnode->data = ndata;
        nnode->next = *head;
        *head = nnode;
    }

    // Add a new node at the end of the linked list.
    void add_at_the_end(linked_list **head, int ndata) {
        linked_list *nnode = new linked_list();
        nnode->data = ndata;

        linked_list *temp = *head;
        nnode->next = NULL;
        if (*head == NULL) {
            *head = nnode;
            return;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
        }
        temp->next = nnode;
    }
    
    void add_at_the_start(linked_list **head, int ndata){
    	linked_list *nnode = new linked_list();
        nnode->data = ndata;
		
        linked_list *temp = *head;
        nnode->next = *head;
        *head=nnode;
    }
    
    void add_at_position(linked_list **head, int position, int ndata) {
        linked_list *nnode = new linked_list();
        nnode->data = ndata;

        if (position == 1) {
            nnode->next = *head;
            *head = nnode;
            return;
        }

        linked_list *temp = *head;
        for (int i = 0; i < position - 2 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        nnode->next = temp->next;
        temp->next = nnode;
    }
    
    void delete_last_node(linked_list **head) {
        if (*head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if ((*head)->next == NULL) {
            delete *head;
            *head = NULL;
            return;
        }

        linked_list *temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    
    void delete_at_position(linked_list **head, int position) {
        if (*head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        linked_list *temp = *head;
        if (position == 1) {
            *head = temp->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != NULL && i < position - 2; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        linked_list *next_node = temp->next->next;
        delete temp->next;
        temp->next = next_node;
    }
    
    void update_at_position(linked_list **head, int position, int new_data) {
        linked_list *temp = *head;
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        temp->data = new_data;
    }

    float find_mean(linked_list *head) {
        float sum = 0;
        int count = 0;
        linked_list *temp = head;
        while (temp != NULL) {
            sum += temp->data;
            count++;
            temp = temp->next;
        }
        return sum / count;
    }

    int find_maximum(linked_list *head) {
        int max_val = INT_MIN;
        linked_list *temp = head;
        while (temp != NULL) {
            if (temp->data > max_val) {
                max_val = temp->data;
            }
            temp = temp->next;
        }
        return max_val;
    }

    int find_minimum(linked_list *head) {
        int min_val = INT_MAX;
        linked_list *temp = head;
        while (temp != NULL) {
            if (temp->data < min_val) {
                min_val = temp->data;
            }
            temp = temp->next;
        }
        return min_val;
    }
	
	//bubble sort
	void sort(linked_list **head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        linked_list *current = *head;
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                sorted = false;
            }
            current = current->next;
        }
    }
}

	
    //Print Linked List Function
    void printList(linked_list *node) {
        while (node != NULL) {
            cout << " " << node->data;
            node = node->next;
        }
    }
};

int main() {
    linked_list *head = NULL;

    linked_list ll;
    ll.push(&head, 5);
    ll.push(&head, 4);
    ll.push(&head, 3);
    ll.push(&head, 2);
    ll.push(&head, 1);
    cout << "Before adding" << endl;
    ll.printList(head);

    ll.add_at_the_end(&head, 6);
    cout << "\nAfter adding at the end" << endl;
    ll.printList(head);
    
    ll.add_at_the_start(&head, 0);
    cout << "\nAfter adding at the start" << endl;
    ll.printList(head);
    
    ll.add_at_position(&head, 3, 7);
    cout << "\nAfter adding at position 3" << endl;
    ll.printList(head);
    
    ll.delete_last_node(&head);
    cout << "\nAfter deleting last node" << endl;
    ll.printList(head);
    
    ll.delete_at_position(&head, 2);
    cout << "\nAfter deleting at position 2" << endl;
    ll.printList(head);
    
    ll.update_at_position(&head, 4, 8);
    cout << "\nAfter updating data at position 4" << endl;
    ll.printList(head);
    
    ll.sort(&head);
    cout << "\nAfter sorting" << endl;
    ll.printList(head);
    
    cout << "\nMaximum value: " << ll.find_maximum(head) << endl;
    cout << "Minimum value: " << ll.find_minimum(head) << endl;
    cout << "Mean value: " << ll.find_mean(head) << endl;

    return 0;
}