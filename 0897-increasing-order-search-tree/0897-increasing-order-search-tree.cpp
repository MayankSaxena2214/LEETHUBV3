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
    void inorder(auto root,auto &in){
        if(root==NULL)return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
   
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)return NULL;
        vector<int>in;
        inorder(root,in);
        
        TreeNode*curr=new TreeNode(in[0]);
        TreeNode*prev=curr;
        for(int i=1;i<in.size();i++){
            TreeNode*temp=new TreeNode(in[i]);
            prev->right=temp;
            prev=temp;
        }
        return curr;

    }
};