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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*curr=head,*prev=NULL,*forw=NULL;
        ListNode*temp=head;
        for(int i=0;i<k;i++){
            if(temp==NULL)return head;
            temp=temp->next;
        }
        int count=0;
        while(count<k && curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            count++;
        }
        if(curr!=NULL){
            head->next=reverseKGroup(curr,k);
        }
        return prev;


    }
};