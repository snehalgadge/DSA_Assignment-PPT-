/**Question 3**
Given a linked list consisting of **L** nodes and given a number **N**. The task is to find the **N**th node from the end of the linked list.

**Example 1:**
Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output:8
Explanation:In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end is 8.
*/

// SOLUTION
void printNthFromLast(struct Node* head, int N)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, N);
    if (++i == N)
        cout<<head->data;
}