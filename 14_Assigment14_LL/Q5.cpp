/*<aside>
💡 **Question 5**

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return *the reordered list*.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.

</aside>*/

// SOLUTION
#include<bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

// A utility function to create a new node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}


void rearrangeEvenOdd(Node *head)
{
if(head==NULL || head->next == NULL){
	// 0 or 1 node
	return;
}
Node* temp = head;
Node* oddStart = NULL; //ODD INDEX
Node* oddEnd = NULL;
Node* evenStart = NULL; //EVEN INDEX
Node* evenEnd = NULL;

int i = 1;
while(temp != NULL){

	if(i%2 ==0){
	//even
	if(evenStart == NULL){
		evenStart = temp;

	}
	else{
		evenEnd->next = temp;

	}
	evenEnd = temp;
	}
	else{
	//odd
	if(oddStart == NULL){
		oddStart = temp;
	}
	else{
		oddEnd->next = temp;
	}
	oddEnd = temp;
	}
	temp = temp->next;
	i++;
}

//now join the odd end with even start
oddEnd->next = evenStart;
//even end is new end so put NULL
evenEnd->next = NULL;

head = oddStart; //new head
}

void printlist(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

// Driver code
int main(void)
{
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);

	cout << "Given Linked List\n";
	printlist(head);

	rearrangeEvenOdd(head);

	cout << "\nModified Linked List\n";
	printlist(head);

	return 0;
}
