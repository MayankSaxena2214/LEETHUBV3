/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*reverse(ListNode*head){
        ListNode*curr=head,*prev=NULL,*forw=NULL;
        while(curr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        
        ListNode*anshead=new ListNode(0);
        ListNode*anstail=anshead;
        while(l1 && l2){
            int total=carry+l1->val+l2->val;
            carry=total/10;
            int digit=total%10;
            ListNode*temp=new ListNode(digit);
            anstail->next=temp;
            anstail=temp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int total=carry+l1->val;
            carry=total/10;
            int digit=total%10;
            ListNode*temp=new ListNode(digit);
            anstail->next=temp;
            anstail=temp;
            l1=l1->next;
            
        }
        while(l2){
            int total=carry+l2->val;
            carry=total/10;
            int digit=total%10;
            ListNode*temp=new ListNode(digit);
            anstail->next=temp;
            anstail=temp;
            l2=l2->next;
        }
        while(carry!=0){
            int total=carry;
            carry=total/10;
            int digit=total%10;
            ListNode*temp=new ListNode(digit);
            anstail->next=temp;
            anstail=temp;
        }
        return anshead->next;
    }
};