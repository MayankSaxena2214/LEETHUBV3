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
            return {true,0};
        }
        auto left=solve(root->left);
        auto right=solve(root->right);
        pair<int,int>curr;
        curr.second=max(left.second,right.second)+1;
        curr.first=left.first&&right.first&&(abs(left.second-right.second)<=1);
        return curr;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};