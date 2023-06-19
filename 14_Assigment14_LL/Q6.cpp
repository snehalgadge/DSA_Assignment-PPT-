/*<aside>
💡 **Question 6**

Given a singly linked list of size **N**. The task is to **left-shift** the linked list by **k** nodes, where **k** is a given positive integer smaller than or equal to length of the linked list.

</aside>*/

// SOLUTION
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

void rotate(Node** head_ref, int k)
{
	if (k == 0)
		return;

	Node* current = *head_ref;

	int count = 1;
	while (count < k && current != NULL) {
		current = current->next;
		count++;
	}

	
	if (current == NULL)
		return;

	Node* kthNode = current;

	while (current->next != NULL)
		current = current->next;

	current->next = *head_ref;
	*head_ref = kthNode->next;
	kthNode->next = NULL;
}

void push(Node** head_ref, int new_data)
{

	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code*/
int main(void)
{
	/* Start with the empty list */
	Node* head = NULL;

	// create a list 10->20->30->40->50->60
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	rotate(&head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}


