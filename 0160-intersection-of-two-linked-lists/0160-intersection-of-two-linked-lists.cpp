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
    ListNode *getIntersectionNode(ListNode *firstHead, ListNode *secondHead) {
        ListNode*ptr1=firstHead;
    ListNode*ptr2=secondHead;
    while(ptr1!=ptr2){
        if(ptr1==NULL){
            ptr1=secondHead;
        }
        else{
            ptr1=ptr1->next;
        }
        if(ptr2==NULL){
            ptr2=firstHead;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    return ptr1;
    }
};