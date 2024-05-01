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
    void solve(auto root,auto& mp,auto &ans,int level)
    {
        if(root==NULL){
            return;
        }
        mp[level]=root->val;
        solve(root->left,mp,ans,level+1);
        solve(root->right,mp,ans,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        int level=0;
        solve(root,mp,ans,level);
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};