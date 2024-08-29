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
    ListNode* reverse(ListNode* head) {
        ListNode*curr=head,*prev=NULL,*forw=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        // l1=reverse(l1);
        // l2=reverse(l2);
        int carry=0;
        ListNode*ansHead=new ListNode(-1);
        ListNode*ansTail=ansHead;
        while(l1!=NULL && l2!=NULL){
            int val=l1->val+l2->val+carry;
            int digit=val%10;
            carry=val/10;
            ansTail->next=new ListNode(digit);
            ansTail=ansTail->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int val=l1->val+carry;
            int digit=val%10;
            carry=val/10;
            ansTail->next=new ListNode(digit);
            ansTail=ansTail->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            int val=l2->val+carry;
            int digit=val%10;
            carry=val/10;
            ansTail->next=new ListNode(digit);
            ansTail=ansTail->next;
            l2=l2->next;
        }
        while(carry!=0){
            int val=carry;
            int digit=val%10;
            carry=val/10;
            ansTail->next=new ListNode(digit);
            ansTail=ansTail->next;
        }
        return ansHead->next;
    }
};