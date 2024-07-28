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
    int solve(TreeNode*root,int&ans){
        if(root==NULL){
            return 0;
        }
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int straight=max(root->val,max(root->val+left,root->val+right));
        int curved=root->val+left+right;
        ans=max(ans,max(straight,curved));
        return straight;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};