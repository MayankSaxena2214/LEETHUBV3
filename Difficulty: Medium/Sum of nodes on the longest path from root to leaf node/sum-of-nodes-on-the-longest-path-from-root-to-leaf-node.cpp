//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void solve(Node*root,int len,int &maxlen,int  sum,int &maxsum){
        if(root==NULL){
            if(len>maxlen){
                maxlen=len;
                maxsum=sum;
                return;
            }
            else if(len==maxlen){
                maxsum=max(sum,maxsum);
                return;
            }
            return;
            
        }
        sum+=root->data;
        solve(root->left,len+1,maxlen,sum,maxsum);
        solve(root->right,len+1,maxlen,sum,maxsum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum=0;
        int maxsum=INT_MIN;
        int len=0,maxlen=0;
        solve(root,len,maxlen,sum,maxsum);
        return maxsum;
    }
};
*/
class Solution
{
public:
    void solve(Node*root,int len,int sum,int &maxlen,int &maxsum){
        if(root==NULL){
            if(len>maxlen){
                maxsum=sum;
                maxlen=len;
                return;
            }
            else if(len==maxlen){
                maxsum=max(sum,maxsum);
                return;
            }
            return;
        }
        sum+=root->data;
        solve(root->left,len+1,sum,maxlen,maxsum);
        solve(root->right,len+1,sum,maxlen,maxsum);
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0,sum=0,maxlen=0,maxsum=0;
        solve(root,len,sum,maxlen,maxsum);
        return maxsum;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends