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
    void solve(auto&root,auto&anstail){
        if(root==NULL)return;
        solve(root->left,anstail);
        anstail->right=new TreeNode(root->val);
        
        anstail=anstail->right;
        solve(root->right,anstail);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)return NULL;
        TreeNode*anshead=new TreeNode(0);
        TreeNode*anstail=anshead;
        solve(root,anstail);
        anshead=anshead->right;
        anshead->left=NULL;
        return anshead;
    }
};