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
    Node* copyRandomList(Node* head) {
        Node*dummy=new Node(0);
        Node*cloneTail=dummy;
        Node*original=head;
        while(original!=nullptr){
            Node*temp=new Node(original->val);
            cloneTail->next=temp;
            cloneTail=temp;
            original=original->next;
        }
        Node*cloneHead=dummy->next;
        Node*cloneNode=cloneHead;
        unordered_map<Node*,Node*>mp;
        original=head;
        while(original!=NULL && cloneNode!=NULL){
            mp[original]=cloneNode;
            original=original->next;
            cloneNode=cloneNode->next;
        }
        original=head;
        cloneNode=cloneHead;
        while(cloneNode!=NULL){
            cloneNode->random=mp[original->random];
            cloneNode=cloneNode->next;
            original=original->next;
        }
        return cloneHead;
    }
};