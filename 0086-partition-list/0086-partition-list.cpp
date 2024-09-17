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
    ListNode* partition(ListNode* head, int x) {
        ListNode*head1=new ListNode(0);
        ListNode*head2=new ListNode(0);
        ListNode*tail1=head1,*tail2=head2;
        ListNode*temp=head;
        while(temp){
            if(temp->val<x){
                tail1->next=temp;
                tail1=temp;
            }
            else{
                tail2->next=temp;
                tail2=temp;
            }
            temp=temp->next;
        }
        tail1->next=NULL;
        tail2->next=NULL;
        tail1->next=head2->next;
        return head1->next;
    }
};