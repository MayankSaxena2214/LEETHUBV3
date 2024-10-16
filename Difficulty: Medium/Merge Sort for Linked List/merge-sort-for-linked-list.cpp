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
    // Function to sort the given linked list using Merge Sort.
    Node*merge(Node*left,Node*right){
        Node*ansHead=new Node(0);
        Node*ansTail=ansHead;
        while(left && right){
            if(left->data<=right->data){
                ansTail->next=left;
                ansTail=left;
                left=left->next;
            }
            else{
                ansTail->next=right;
                ansTail=right;
                right=right->next;
            }
        }
        while(left){
            ansTail->next=left;
                ansTail=left;
                left=left->next;
        }
        while(right){
            ansTail->next=right;
                ansTail=right;
                right=right->next;
        }
        ansTail->next=NULL;
        return ansHead->next;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)return head;
        Node*slow=head;
        Node*fast=head->next;
        
        while(fast!=NULL && fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL)fast=fast->next;
        }
        Node*mid=slow;
        Node*head2=mid->next;
        mid->next=NULL;
        Node*left=mergeSort(head);
        Node*right=mergeSort(head2);
        Node*ans=merge(left,right);
        return ans;
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