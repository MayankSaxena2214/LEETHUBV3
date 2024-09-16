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
    int solve(auto&root){
        if(root==NULL)return 0;
        auto left=solve(root->left);
        auto right=solve(root->right);
        return max(left,right)+1;
    }
    int maxDepth(TreeNode* root) {
        
        return solve(root);
        
    }
};