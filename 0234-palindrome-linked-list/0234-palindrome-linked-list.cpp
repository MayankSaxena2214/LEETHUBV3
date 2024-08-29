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
    ListNode*getMid(auto head){
        ListNode*slow=head,*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        ListNode*middle=getMid(head);
        ListNode*head2=middle->next;
        head2=reverse(head2);
        middle->next=NULL;
        // cout<<head2->val<<endl;
        // cout<<head2->next->val<<endl;
        while(head!=NULL && head2!=NULL){
            if(head->val!=head2->val){
                return false;
            }
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};