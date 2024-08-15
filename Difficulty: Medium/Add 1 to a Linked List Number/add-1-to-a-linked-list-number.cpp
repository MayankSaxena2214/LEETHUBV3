//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node*reverse(Node*head){
        Node*prev=NULL,*forw=NULL,*curr=head;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    void insertTail(Node*&anshead,Node*&anstail,int digit){
        Node*ptr=new Node(digit);
        if(anshead==NULL){
            anshead=anstail=ptr;
            
        }
        else{
            anstail->next=ptr;
            anstail=ptr;
        }
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(head==NULL)return new Node(1);
        int carry=1;
        head=reverse(head);
        Node*temp=head;
        Node*anshead=NULL;
        Node*anstail=anshead;
        while(temp!=NULL){
            int total=temp->data+carry;
            int digit=total%10;
            carry=total/10;
            insertTail(anshead,anstail,digit);
            temp=temp->next;
            
        }
        while(carry!=0){
            int total=carry;
            int digit=total%10;
            carry=total/10;
            Node*ptr=new Node(digit);
            anstail->next=ptr;
            anstail=ptr;
        }
        anshead=reverse(anshead);
        return anshead;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends