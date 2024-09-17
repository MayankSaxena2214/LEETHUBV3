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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode*fb=headA;
        ListNode*wg=headB;
        while(fb!=wg){
            if(fb==NULL)fb=headB;
            else fb=fb->next;
            if(wg==NULL)wg=headA;
            else wg=wg->next;
        }
        return fb;
    }
};