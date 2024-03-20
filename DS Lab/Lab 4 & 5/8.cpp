#include <iostream>
using namespace std;

class Node 
{
	public:
	int data;
	Node* next;
};

void rotate(Node** head_ref, int k)
{
	if (k == 0)
		return;

	Node* current = *head_ref;
	while (current->next != NULL)
		current = current->next;

	current->next = *head_ref;
	current = *head_ref;

	for (int i = 0; i < k - 1; i++)
		current = current->next;
	*head_ref = current->next;
	current->next = NULL;
}
void push(Node** head_ref, 
		int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) 
	{
		cout << node->data << " ";
		node = node->next;
	}
}
int main(void)
{
	Node* head = NULL;
	for (int i = 6; i > 0; i -= 1)
		push(&head, i);

	cout << "Given linked list ";
	printList(head);
	rotate(&head, 4);

	cout << endl << "Rotated Linked list ";
	printList(head);

	return (0);
}