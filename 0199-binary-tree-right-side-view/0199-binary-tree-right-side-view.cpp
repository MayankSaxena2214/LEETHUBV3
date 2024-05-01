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
    void solve(TreeNode*root,int index,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(index==ans.size()){
        ans.push_back(root->val);
        
    }
    solve(root->right,index+1,ans);
    solve(root->left,index+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
         int index=0;
   vector<int>ans;
   solve(root,index,ans);
   return ans;
    }
};

    
    
    

    //Function to return list containing elements of right view of binary tree.
    