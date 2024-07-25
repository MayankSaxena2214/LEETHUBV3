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
        if(root==NULL)return {};
        vector<vector<int>>ans;
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            TreeNode*top=front.first;
            int hd=front.second.first;
            int lvl=front.second.second;
            mp[hd][lvl].push_back(top->val);
            if(top->left)q.push({top->left,{hd-1,lvl+1}});
            if(top->right)q.push({top->right,{hd+1,lvl+1}});
        }
        for(auto i:mp){
            vector<int>temp;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;

    }
};