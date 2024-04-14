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
    void traverse(auto root,auto&ans){
        if(root==NULL)return;
        auto temp=root->left;
        if(temp!=NULL)
        if(temp->left==NULL && temp->right==NULL){
            ans+=temp->val;
        }
        traverse(root->left,ans);
        traverse(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
       int ans=0;
       traverse(root,ans);
       return ans;
    }
};