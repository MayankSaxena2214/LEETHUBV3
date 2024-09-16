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
    static const int e=1e9+7;
    long long getSum(auto&root){
        if(root==NULL)return 0;
        return root->val+getSum(root->left)+getSum(root->right);
    }
    long long int solve(auto&root,auto&maxi,auto&total){
        if(root==NULL){
            return 0;
        }
        long long subtreesum=root->val;
        subtreesum+=solve(root->left,maxi,total);
        subtreesum+=solve(root->right,maxi,total);
        if((total-subtreesum)*subtreesum>maxi){
            maxi=(total-subtreesum)*subtreesum;
        }
        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        long long sum=getSum(root);
        long long int maxi=INT_MIN;
        solve(root,maxi,sum);
        return maxi%e;
    }
};