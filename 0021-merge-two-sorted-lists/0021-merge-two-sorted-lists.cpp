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
    ListNode*solve(ListNode*first,ListNode*second){
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    ListNode*curr1=first,*next1=curr1->next,*curr2=second,*next2=NULL;
    while(curr2!=NULL && next1!=NULL){
        if(curr2->val>=curr1->val && curr2->val<=next1->val){
            //we can insert the curr2 inside the curr1 and next1
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2; 
        }
        else{
            //curr1 and next1 ko aage badhao
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
         // Write your code here.
    if(first==NULL)return second;
    if(second==NULL)return first;
   
    if(first->val<second->val){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
    }
};