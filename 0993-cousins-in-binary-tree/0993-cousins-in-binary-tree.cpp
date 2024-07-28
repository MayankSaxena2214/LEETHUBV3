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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
      return false;
    queue<TreeNode*>q;
    q.push(root);
    bool marker=true;
    while(!q.empty() && marker){
        int n=q.size();
        for(int i=0;i<n;i++){
            auto front=q.front();
            q.pop();

            if((front->left && front->left->val==x) || (front->right && front->right->val==x)){
                marker=false;
            }
            else{
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
        }
    }
    
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        if(front->val==y)return true;
    }
    return false;
    }
};