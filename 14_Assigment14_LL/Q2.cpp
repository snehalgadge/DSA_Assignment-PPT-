/*<aside>
💡 **Question 2**

A number **N** is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

</aside>*/

// SOLUTION

#include <bits/stdc++.h>
using namespace std;

/* Linked list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* Function to create a new node with given data */
Node *newNode(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to reverse the linked list */
Node *reverse(Node *head)
{
	Node * prev = NULL;
	Node * current = head;
	Node * next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}


Node *addOneUtil(Node *head)
{
	// res is head node of the resultant list
	Node* res = head;
	Node *temp;

	int carry = 1, sum;

	while (head != NULL) //while both lists exist
	{
	
		sum = carry + head->data;

		// update carry for next calculation
		carry = (sum >= 10)? 1 : 0;

		// update sum if it is greater than 10
		sum = sum % 10;

		// Create a new node with sum as data
		head->data = sum;

		// Move head and second pointers to next nodes
		temp = head;
		head = head->next;
	}

	// if some carry is still there, add a new node to
	// result list.
	if (carry > 0)
		temp->next = newNode(carry);

	// return head of the resultant list
	return res;
}

// This function mainly uses addOneUtil().
Node* addOne(Node *head)
{
	// Reverse linked list
	head = reverse(head);

	// Add one from left to right of reversed
	// list
	head = addOneUtil(head);

	// Reverse the modified list
	return reverse(head);
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data;
		node = node->next;
	}
	cout<<endl;
}

int main(void)
{
	Node *head = newNode(1);
	head->next = newNode(9);
	head->next->next = newNode(9);
	head->next->next->next = newNode(9);

	cout << "List is ";
	printList(head);

	head = addOne(head);

	cout << "\nResultant list is ";
	printList(head);

	return 0;
}


