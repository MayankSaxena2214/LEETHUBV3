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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        map<int,map<int,vector<int> > > mp;
        queue<pair<TreeNode*,pair<int,int> > > q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto ans=q.front();
            q.pop();
            TreeNode*front=ans.first;
            int hd=ans.second.first;
            int lvl=ans.second.second;
            mp[hd][lvl].push_back(front->val);
            if(front->left){
                q.push({front->left,{hd-1,lvl+1}});
            }
            if(front->right){
                q.push({front->right,{hd+1,lvl+1}});
            }
        }
        // for(auto i:mp){
        //     for(auto j:i.second)
        //         ans.push_back(j.second);
        // }
        for(auto i:mp){
            vector<int>v;
            for(auto j:i.second){
            sort(j.second.begin(), j.second.end());
                for(auto k:j.second){
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};