//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
#include<bits/stdc++.h>
class Solution{
    public:
    Node*solve(int*in,int*pre,int&index,int st,int end,int n,unordered_map<int,bool>&mp){
        if(index>=n || st>end){
            return NULL;
        }
        int data=pre[index++];
        Node*root=new Node(data);
        int pos=-1;
        for(int i=st;i<=end;i++){
            if(in[i]==data){
                pos=i;
                break;
            }
        }
        root->left=solve(in,pre,index,st,pos-1,n,mp);
        root->right=solve(in,pre,index,pos+1,end,n,mp);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int index=0;
        
        unordered_map<int,bool>mp;
      
        return solve(in,pre,index,0,n-1,n,mp);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends