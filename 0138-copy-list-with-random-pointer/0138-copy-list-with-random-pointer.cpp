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
        Node*cloneHead=new Node(-1);
        Node*cloneTail=cloneHead;
        Node*original=head;
        unordered_map<Node*,Node*>mp;
        while(original!=NULL){
            Node*temp=new Node(original->val);
            cloneTail->next=temp;
            cloneTail=temp;
            mp[original]=cloneTail;
            original=original->next;
        }
        Node*clone=cloneHead->next;
        original=head;
        while(original!=NULL && clone!=NULL){
            clone->random=mp[original->random];
            clone =clone->next;
            original=original->next;
        }
        return cloneHead->next;

    }
};