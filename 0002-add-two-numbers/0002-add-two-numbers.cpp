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
    void insertTail(ListNode*&anshead,ListNode*&anstail,int data){
        ListNode*temp=new ListNode(data);
        if(anshead==NULL){
            anshead=anstail=temp;
            return;
        }
        else{
            anstail->next=temp;
            anstail=temp;
        }
    }
    ListNode*reverse(ListNode*&head){
        if(head==NULL || head->next){
            return head;
        }
        ListNode*curr=head,*prev=NULL,*forw=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head1=l1;
        cout<<"l1->data is:"<<head1->val<<endl;
        ListNode*head2=l2;
        cout<<"l2->data is:"<<head2->val<<endl;
        int carry=0;
        ListNode*anshead=NULL,*anstail=NULL;
        while(head1!=NULL && head2!=NULL){
            int val1=head1->val;
            int val2=head2->val;
            int sum=carry+val1+val2;
            int digit=sum%10;
            carry=sum/10;
            insertTail(anshead,anstail,digit);
            head1=head1->next;
            head2=head2->next;
        }
        while(head1!=NULL){
            int val1=head1->val;
            int sum=carry+val1;
             int digit=sum%10;
            carry=sum/10;
            insertTail(anshead,anstail,digit);
            head1=head1->next;
        }
         while(head2!=NULL){
            int val1=head2->val;
            int sum=carry+val1;
             int digit=sum%10;
            carry=sum/10;
            insertTail(anshead,anstail,digit);
            head2=head2->next;
        }
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            insertTail(anshead,anstail,digit);
            carry=sum/10;

        }
        return reverse(anshead);
    }
    
};