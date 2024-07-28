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
const int M=1e9+7;
    long long getTotal(TreeNode*root){
        if(root==NULL)return 0;
        return root->val+getTotal(root->left)+getTotal(root->right);
    }
    long long solve(TreeNode*root,long long&ans,long long total){
        if(root==NULL)return 0;
        long long subtree=0;
        subtree+=root->val;
        subtree+=solve(root->left,ans,total);
        subtree+=solve(root->right,ans,total);
        if((total-subtree)*subtree>ans){
            ans=(total-subtree)*subtree;

        }
        return subtree;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL)return 0;
        long long total=getTotal(root);
        long long ans=INT_MIN;
        solve(root,ans,total);
        return ans%M;
    }
};