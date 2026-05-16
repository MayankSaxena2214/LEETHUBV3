/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
class info{
        public:
        int maxi,mini,size,sum;
        bool isBST;
        
        info(int maxi,int mini,int size,int sum,bool isBST){
            this->maxi=maxi;
            this->mini=mini;
            this->size=size;
            this->isBST=isBST;
            this->sum=sum;
        }
    };
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    info solve(TreeNode*root,int &ans){
        if(root==NULL){
            return info(INT_MIN,INT_MAX,0,0,true);
        }
        auto leftans=solve(root->left,ans);
        auto rightans=solve(root->right,ans);
        
        info curr(0,0,0,0,true);
        curr.size=leftans.size+rightans.size+1;
        curr.maxi=max(root->val,rightans.maxi);
        curr.mini=min(root->val,leftans.mini);
        curr.sum=leftans.sum+rightans.sum+root->val;
        if(leftans.isBST && rightans.isBST && root->val > leftans.maxi && root->val < rightans.mini){
            curr.isBST=true;
        }
        else curr.isBST=false;
        
        if(curr.isBST){
            ans=max(ans,curr.sum);

        }
        
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return max(ans,0);
    }
};