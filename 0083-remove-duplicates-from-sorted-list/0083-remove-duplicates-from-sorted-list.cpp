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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode*curr=head,*prev=NULL;
        while(curr){
            if(curr->next!=NULL && curr->val==curr->next->val){
                //duplicate found
                int val=curr->val;
                prev=curr->next;
                while(prev && prev->val==val){
                    prev=prev->next;
                }
                curr->next=prev;
                curr=prev;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};