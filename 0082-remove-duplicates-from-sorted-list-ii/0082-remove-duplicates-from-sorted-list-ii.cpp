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
        ListNode*dummy=new ListNode(0);
        ListNode*prev=dummy;
        dummy->next=head;
        ListNode*curr=head;
        while(prev->next && prev->next->next){
            if(prev->next->val==prev->next->next->val){
                int value=prev->next->val;
                ListNode*curr=prev->next;
                while(curr!=NULL && curr->val==value){
                    curr=curr->next;
                }
                prev->next=curr;
            }
            else{

                prev=prev->next;
            }
        }
        return dummy->next;
    }
};