/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertTail(auto&anshead,auto&anstail,int digit){
        Node*temp=new Node(digit);
        if(anshead==NULL){
            anshead=anstail=temp;
            return;
        }
        else{
            anstail->next=temp;
            anstail=temp;
        }
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        //clone the list with next pointer
        Node*originalNode=head;
        Node*cloneHead=NULL,*cloneTail=NULL;
        while(originalNode!=NULL){
            insertTail(cloneHead,cloneTail,originalNode->val);
            originalNode=originalNode->next;
        }
        //create mapping
        Node*cloneNode=cloneHead;
        originalNode=head;
        unordered_map<Node*,Node*>mp;
        while(originalNode!=NULL && cloneNode!=NULL){
            mp[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            cloneNode->random=mp[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};