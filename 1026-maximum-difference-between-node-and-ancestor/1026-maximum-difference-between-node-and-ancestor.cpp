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
    void  solve(TreeNode*root, int &ans ,int maxi,int mini){
       if(root==NULL){
        
       return;
       };
       ans=max(ans,abs(root->val-mini));
       ans=max(ans,abs(root->val-maxi));
       maxi=max(maxi,root->val);
       mini=min(mini,root->val);

       solve(root->left,ans,maxi,mini);
       solve(root->right,ans,maxi,mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0;
        solve(root,ans,root->val,root->val);
        return ans;
    }
};