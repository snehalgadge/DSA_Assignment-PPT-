/*<aside>
💡 **Question 4**

You are given a special linked list with **N** nodes where each node has a next pointer pointing to its next node. You are also given **M** random pointers, where you will be given **M** number of pairs denoting two nodes **a** and **b**  **i.e. a->arb = b** (arb is pointer to random node)**.**

Construct a copy of the given list. The copy should consist of exactly **N** new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes **X** and **Y** in the original list, where **X.arb** **-->** **Y**, then for the corresponding two nodes **x** and **y** in the copied list, **x.arb --> y.**

Return the head of the copied linked list.

</aside>*/

// SOLUTION
#include <bits/stdc++.h>
using namespace std;

// Structure of a node of linked list
struct Node {
	int val;
	Node* next;
	Node* arbit;

	// Constructor
	Node(int x)
	{
		this->val = x;
		this->next = NULL;
		this->arbit = NULL;
	}
};

// Function to clone the linked list
Node* cloneLinkedList(Node* head)
{
	// Map to store the mapping of
	// old nodes with new ones
	unordered_map<Node*, Node*> mp;
	Node *temp, *nhead;

	// Duplicate of the first node
	temp = head;
	nhead = new Node(temp->val);
	mp[temp] = nhead;

	// Loop to create duplicates of nodes
	// with only next pointer
	while (temp->next != NULL) {
		nhead->next
			= new Node(temp->next->val);
		temp = temp->next;
		nhead = nhead->next;
		mp[temp] = nhead;
	}
	temp = head;

	// Loop to clone the arbit pointers
	while (temp != NULL) {
		mp[temp]->arbit = mp[temp->arbit];
		temp = temp->next;
	}

	// Return the head of the clone
	return mp[head];
}

// Function to print the linked list
void printList(Node* head)
{
	cout << head->val << "("
		<< head->arbit->val << ")";
	head = head->next;
	while (head != NULL) {
		cout << " -> " << head->val << "("
			<< head->arbit->val << ")";
		head = head->next;
	}
	cout << endl;
}

// Driver code
int main()
{
	// Creating a linked list with random pointer
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next
		= new Node(5);
	head->arbit = head->next->next;
	head->next->arbit = head;
	head->next->next->arbit
		= head->next->next->next->next;
	head->next->next->next->arbit
		= head->next->next;
	head->next->next->next->next->arbit
		= head->next;

	// Print the original list
	cout << "The original linked list:\n";
	printList(head);

	// Function call
	Node* sol = cloneLinkedList(head);

	cout << "The cloned linked list:\n";
	printList(sol);

	return 0;
}
