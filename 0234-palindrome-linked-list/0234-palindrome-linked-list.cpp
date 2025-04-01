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
    bool isPalindrome(ListNode* head) {
        //find mid
        if(head==NULL || head->next==NULL)return head;
        ListNode*middle=NULL;
        ListNode*first=head;
        ListNode*second=first;
        while(second && second->next){
            middle=first;
            first=first->next;
            second=second->next;
            if(second)second->next;

        }
        if(!middle->next)return false;
        //break into the two list
        ListNode*head2=reverse(middle->next);
        middle->next=NULL;
        ListNode*head1=head;
        while(head1 && head2){
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};