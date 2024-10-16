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
    ListNode*getMid(ListNode*head){
        if(head==NULL)return NULL;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast){
                fast=fast->next;
            }
        }
        return slow;
    }
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
        //reverse after mid
        ListNode*mid=getMid(head);
        cout<<mid->val<<endl;
        ListNode*head2=mid->next;
        head2=reverse(head2);
        mid->next=NULL;
        while(head && head2){
            if(head->val!=head2->val)return false;
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};