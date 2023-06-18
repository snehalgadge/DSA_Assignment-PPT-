/**Question 1**
Given a singly linked list, delete **middle** of the linked list. For example, if given linked list is 1->2->**3**->4->5 then linked list should be modified to 1->2->4->5.If there are **even** nodes, then there would be **two middle** nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.If the input linked list is NULL or has 1 node, then it should return NULL

**Example 1:**
Input:
LinkedList: 1->2->3->4->5
Output:1 2 4 5
*/

// SOLUTION
ListNode* deleteMiddle(ListNode* head) {
          if(head->next==NULL) return nullptr;
   int nods=0;
   ListNode *q,*p = head;
   while(p)
   {
    nods++;
    p=p->next;
   }
   p=head;
   q=nullptr;
   nods = (nods/2);
   
   while(nods--)
   {
    q=p;
    p=p->next;
   }
   
   q->next = p->next;

   return head;
    }