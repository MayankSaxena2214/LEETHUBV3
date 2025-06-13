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
        ListNode*ansHead=new ListNode(0);
        ListNode*ansTail=ansHead;
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        while(temp1 && temp2){
            if(temp1->val<=temp2->val){
                ansTail->next=temp1;
                ansTail=temp1;
                temp1=temp1->next;
            }
            else{
                ansTail->next=temp2;
                ansTail=temp2;
                temp2=temp2->next;
            }
        }
        while(temp1){
            ansTail->next=temp1;
                ansTail=temp1;
                temp1=temp1->next;
        }
        while(temp2){
            ansTail->next=temp2;
                ansTail=temp2;
                temp2=temp2->next;
        }
        ansTail->next=NULL;
        return ansHead->next;
    }
};