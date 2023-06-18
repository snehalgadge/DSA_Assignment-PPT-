/**Question 5**

Given a linked list of **N** nodes such that it may contain a loop.
A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.
Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

**Example 1:**
Input:
N = 3
value[] = {1,3,4}
X = 2
Output:1
Explanation:The link list looks like
1 -> 3 -> 4
     ^    |
     |____|
A loop is present. If you remove it
successfully, the answer will be 1.
*/

// SOLUTION

struct Node {
	int key;
	struct Node* next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

void detectAndRemoveLoop(Node* head)
{
	
	if (head == NULL || head->next == NULL)
		return;

	Node *slow = head, *fast = head;

	slow = slow->next;
	fast = fast->next->next;

	while (fast && fast->next) {
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast) {
		slow = head;
		if (slow == fast)
			while (fast->next != slow)
				fast = fast->next;
		else {
			while (slow->next != fast->next) {
				slow = slow->next;
				fast = fast->next;
			}
		}		
		fast->next = NULL; 
	}
}

