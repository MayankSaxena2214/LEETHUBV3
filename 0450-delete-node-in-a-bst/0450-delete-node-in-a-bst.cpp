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
TreeNode*mini(TreeNode*root){
    TreeNode*temp=root;
    TreeNode*ans=NULL;
    while(temp!=NULL){
        ans=temp;
        temp=temp->left;
    }
    return ans;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            else if(root->left==NULL){
                return root->right;
            }
            else if(root-> right==NULL && root->left!=NULL){
                return root->left;
            }
            else{
                int val=mini(root->right)->val;
                root->val=val;
                root->right=deleteNode(root->right,val);
                return root;
            }
        }
        else if(root->val > key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
    }
};