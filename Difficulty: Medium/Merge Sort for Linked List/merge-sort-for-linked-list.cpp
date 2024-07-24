//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  Node *getMid(Node *&head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
    }
    return slow;
}
Node*merge(Node*head1,Node*head2){
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    Node*anshead=new Node(-1);
    Node*anstail=anshead;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            anstail->next=head1;
            anstail=head1;
            head1=head1->next;
        }
        else{
            anstail->next=head2;
            anstail=head2;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        anstail->next=head1;
            anstail=head1;
            head1=head1->next;
    }
    while(head2!=NULL){
            anstail->next=head2;
            anstail=head2;
            head2=head2->next;
    }
    return anshead->next;
}
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)return head;
    Node*middle=getMid(head);
    Node*head1=head;
    Node*head2=middle->next;
    middle->next=NULL;

    head1=mergeSort(head1);
    head2=mergeSort(head2);

    return merge(head1,head2);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends