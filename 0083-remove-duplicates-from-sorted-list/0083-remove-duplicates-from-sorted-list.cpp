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
        ListNode*temp=head;
        ListNode*anshead=new ListNode(0);
        ListNode*anstail=anshead;
        anshead->next=head;
        while(temp){
            if(temp!=NULL && temp->next && temp->val==temp->next->val){
                int value=temp->val;
                while(temp && temp->next && temp->next->val==value){
                    temp=temp->next;
                }
                anstail->next=temp;
                anstail=temp;
                temp=temp->next;
            }
            else{
                anstail->next=temp;
                anstail=temp;
                temp=temp->next;
            }
        }   
        return anshead->next;
    }
};