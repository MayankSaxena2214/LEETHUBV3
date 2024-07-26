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
    TreeNode* getMini(TreeNode*root){
        if(root==NULL)return NULL;
        TreeNode*temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL){
                return root->right;
            }
            else if(root->left!=NULL && root->right==NULL){
                return root->left;
            }
            else{
                int mini=getMini(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else {
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};