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
    pair<ListNode*,ListNode*> findMiddle(auto&head){
        ListNode*prev=NULL;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL){
            
            
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            else{
                break;
            }
            prev=slow;
            slow=slow->next;
        }
        return {prev,slow};
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)return head;
        if(head->next==NULL)return NULL;
        auto tempans=findMiddle(head);
        auto middle=tempans.second;
        
        auto prev=tempans.first;
        cout<<middle->val<<" "<<prev->val<<endl;
        if(middle->next==NULL){
            prev->next=NULL;
            return head;
        }
        else{
            prev->next=middle->next;
            delete middle;
            return head;
        }
    }
};