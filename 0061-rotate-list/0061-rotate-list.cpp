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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        ListNode*temp=head;
        int len=0;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        temp->next=head;
        if(k>len){
            k=k%(len+1);
        }
        if(k==0){
            temp->next=NULL;
            return head;
        }
        int moves=k+1;
        ListNode*curr=head,*temp1=curr;
        while(moves!=0){
            temp1=curr;
            curr=curr->next;
            moves--;
        }
        temp1->next=NULL;
        return curr;
    }
};