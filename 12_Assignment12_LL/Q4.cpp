/**Question 4**
Given a singly linked list of characters, write a function that returns true if the given list is a palindrome, else false.

**Examples:** 
**Input:** C->O->D->E->NULL 
**Output:** No
*/

// SOLUTION
ListNode* reverse(ListNode* head){
        if(head==NULL) return head;
        ListNode *p=NULL,*c=head,*n=head->next;
        
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL)n=n->next;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow=head,*fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverse(slow->next);
        ListNode *start=head,*mid=slow->next;
        
        while(mid!=NULL){
            
            if(start->val!=mid->val)return false;
            
            else{
                start=start->next;
                mid=mid->next;
            }
        }
        slow->next=reverse(slow->next);
        return true;
    }