/*<aside>
💡 **Question 7**

You are given the `head` of a linked list with `n` nodes.

For each node in the list, find the value of the **next greater node**. That is, for each node, find the value of the first node that is next to it and has a **strictly larger** value than it.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the `ith` node (**1-indexed**). If the `ith` node does not have a next greater node, set `answer[i] = 0`.

</aside>*/

// SOLUTION
#include <bits/stdc++.h>
using namespace std;

// List Node
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
	{
		val = x;
		next = NULL;
	}
};

// Function to reverse the LL
void rev(ListNode** head)
{
	ListNode *pre, *curr, *nex;

	pre = NULL;
	curr = *head;
	nex = curr->next;

	// Till current is not NULL
	while (curr) {
		curr->next = pre;
		pre = curr;
		curr = nex;
		nex = (curr)
				? curr->next
				: NULL;
	}
	*head = pre;
}

// Function to print a LL node
void printList(ListNode* head)
{
	while (head) {

		cout << head->val
			<< ' ';
		head = head->next;
	}
}

// Function to find the next greater
// element in the list
ListNode* nextLargerLL(ListNode* head)
{
	if (head == NULL)
		return NULL;

	// Dummy Node
	ListNode* res
		= new ListNode(-1);
	ListNode* temp = res;

	// Reverse the LL
	rev(&head);
	stack<int> st;

	while (head) {

		// Initial Condition
		if (st.empty()) {
			temp->next
				= new ListNode(0);
			st.push(head->val);
		}
		else {

			// Maintain Monotonicity
			// Decreasing stack of element
			while (!st.empty()
				&& st.top()
						<= head->val)
				st.pop();

			// Update result LL
			if (st.empty()) {
				temp->next
					= new ListNode(0);

				st.push(head->val);
			}
			else {
				temp->next
					= new ListNode(st.top());
				st.push(head->val);
			}
		}
		head = head->next;
		temp = temp->next;
	}

	// Delete Dummy Node
	temp = res;
	res = res->next;
	delete temp;

	// Reverse result LL
	rev(&res);
	return res;
}

// Driver Code
int main()
{
	// Given Linked List
	ListNode* head = new ListNode(2);
	ListNode* curr = head;

	curr->next = new ListNode(1);
	curr = curr->next;

	curr->next = new ListNode(3);
	curr = curr->next;

	curr->next = new ListNode(0);
	curr = curr->next;

	curr->next = new ListNode(5);
	curr = curr->next;

	// Function Call
	printList(nextLargerLL(head));
	return 0;
}

