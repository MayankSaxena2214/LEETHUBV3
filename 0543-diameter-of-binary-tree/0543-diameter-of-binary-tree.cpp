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
    pair<int,int> solve(auto&root){
        if(root==NULL){
            return {0,0};
        }
        auto left=solve(root->left);
        auto right=solve(root->right);
        pair<int,int>curr;
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        curr.first=max(op1,max(op2,op3));
        curr.second=max(left.second,right.second)+1;
        return curr;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};