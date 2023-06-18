/**Question 6**

Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till end of the linked list.
Difficulty Level: Rookie

**Examples**:
Input:
M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
Output:
Linked List: 1->2->5->6
*/

// SOLUTION

class Node
{
	public:
	int data;
	Node *next;
};

void push(Node ** head_ref, int new_data)
{
	
	Node* new_node = new Node();

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}


void skipMdeleteN(Node *head, int M, int N)
{
	Node *curr = head, *t;
	int count;

	while (curr)
	{
	
		for (count = 1; count < M &&
				curr!= NULL; count++)
			curr = curr->next;

		if (curr == NULL)
			return;
		t = curr->next;
		for (count = 1; count<=N && t!= NULL; count++)
		{
			Node *temp = t;
			t = t->next;
			free(temp);
		}
		
		curr->next = t;
		curr = t;
	}
}

