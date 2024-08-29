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
    ListNode*getIntersect(ListNode*head){
    ListNode*slow=head,*fast=head;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)fast=fast->next;
        if(slow==fast)return slow;
    }
    return NULL;
}
ListNode*getCycle(ListNode*head){
    if(head==NULL)return NULL;
    ListNode*intersect=getIntersect(head);
    if(intersect==NULL)return NULL;
    ListNode*temp=head;
    while(temp!=intersect){
        temp=temp->next;
        intersect=intersect->next;
    }
    return temp;
}
    ListNode *detectCycle(ListNode *head) {
        return getCycle(head);
    }
};