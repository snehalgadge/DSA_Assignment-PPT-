/*<aside>
💡 **Question 8**

Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to `0` until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of `ListNode` objects.)

</aside>*/

// SOLUTIION
#include <bits/stdc++.h>
using namespace std;

// A Linked List Node
struct ListNode {
	int val;
	ListNode* next;

	// Constructor
	ListNode(int x)
		: val(x)
		, next(NULL)
	{
	}
};

// Function to create Node
ListNode* getNode(int data)
{
	ListNode* temp;
	temp = (ListNode*)malloc(sizeof(ListNode));
	temp->val = data;
	temp->next = NULL;
	return temp;
}

// Function to print the Linked List
void printList(ListNode* head)
{
	while (head->next) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << head->val;
}

// Function that removes continuous nodes
// whose sum is K
ListNode* removeZeroSum(ListNode* head, int K)
{
	// Root node initialise to 0
	ListNode* root = new ListNode(0);

	// Append at the front of the given
	// Linked List
	root->next = head;

	// Map to store the sum and reference
	// of the Node
	unordered_map<int, ListNode*> umap;

	umap[0] = root;

	// To store the sum while traversing
	int sum = 0;

	// Traversing the Linked List
	while (head != NULL) {

		// Find sum
		sum += head->val;
		//if sum is found with k, we would be needed
		// to delete the head node
		// so we need a reference pointer to its next
		ListNode* headNext = head->next;

		// If found value with (sum - K)
		if (umap.find(sum - K) != umap.end()) {

			ListNode* prev = umap[sum - K];
			ListNode* start = prev;


			

			// Update sum
			sum = sum - K;
			int aux = sum;
			// move prev to the first node which need to deleted in nodes with sum K
			prev = prev->next;
			// Traverse till current head
			while (prev != head) {
				// temp will store the prev node address to free it from memory
				ListNode* temp = prev;
				aux += prev->val;
				if (prev != head) {
					umap.erase(aux);
				}
				prev = prev->next;
				delete temp;
			}

			// Update the start value to
			// the next value of current head
			delete head;
			start->next = headNext;
		}

		// If (sum - K) value not found
		else if (umap.find(sum) == umap.end()) {
			umap[sum] = head;
		}

		head = headNext;
	}

	// Return the value of updated
	// head node
	return root->next;
}

// Driver Code
int main()
{
	// head Node
	ListNode* head;

	// Create Linked List
	head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(-3);
	head->next->next->next = getNode(3);
	head->next->next->next->next = getNode(1);

	// Given sum K
	int K = 5;

	// Function call to get head node
	// of the updated Linked List
	head = removeZeroSum(head, K);

	// Print the updated Linked List
	if (head != NULL)
		printList(head);
	return 0;
}
