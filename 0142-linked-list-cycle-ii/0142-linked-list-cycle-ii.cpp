/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            
            
            if(fast!=NULL){
                fast=fast->next;
            }
            if(slow==fast)break;

        }
        if(fast==NULL){
            return NULL;
        }
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        cout<<slow->val<<endl;
        return slow;
    }
};