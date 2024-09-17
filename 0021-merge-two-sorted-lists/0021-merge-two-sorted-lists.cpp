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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*first=list1;
        ListNode*second=list2;
        ListNode*anshead=new ListNode(0);
        ListNode*anstail=anshead;
        while(first && second){
            if(first->val<second->val){
                anstail->next=first;
                anstail=first;
                first=first->next;
            }
            else{
                anstail->next=second;
                anstail=second;
                second = second->next;
            }
        }
        while(first){
            anstail->next=first;
            anstail=first;
            first=first->next;
        }
        while(second){
            anstail->next=second;
            anstail=second;
            second = second->next;
        }
        return anshead->next;
    }
};