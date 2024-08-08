//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    void insertTail(Node*&anshead,Node*&anstail,int data){
        Node*temp=new Node(data);
        if(anshead==NULL){
            anshead=anstail=temp;
            
        }
        else{
            anstail->next=temp;
            anstail=temp;
        }
    }
    struct Node* reverse(struct Node* head) {
        // code here
        // return head of reversed list
        Node*prev=NULL,*curr=head,*forw=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    Node* addTwoLists(struct Node* num1, struct Node* num2) {
        // code here
        if(num1==NULL)return num2;
        if(num2==NULL)return num1;
        Node*first=reverse(num1);
        Node*second=reverse(num2);
        int carry=0;
        Node*anshead=NULL,*anstail=NULL;
        while(first!=NULL && second!=NULL){
            int total=first->data+second->data+carry;
            int digit=total%10;
            carry=total/10;
            insertTail(anshead,anstail,digit);
            first=first->next;
            second=second->next;
        }
        while(first!=NULL){
             int total=first->data+carry;
            int digit=total%10;
            carry=total/10;
            insertTail(anshead,anstail,digit);
            first=first->next;
            
        }  
        while(second!=NULL){
             int total=second->data+carry;
            int digit=total%10;
            carry=total/10;
            insertTail(anshead,anstail,digit);
            
            second=second->next;
        }
        while(carry!=0){
            int total=carry;
            int digit=total%10;
            carry=total/10;
            insertTail(anshead,anstail,digit);
        }
        anshead=reverse(anshead);
        while(anshead!=NULL && anshead->data==0){
            anshead=anshead->next;
        }
        if(anshead==NULL){
            return new Node(0);
        }
        else{
            return anshead;
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends