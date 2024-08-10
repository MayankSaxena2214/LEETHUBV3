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
    TreeNode*mapping(TreeNode*root,int target,unordered_map<TreeNode*,TreeNode*>&mp){
        if(root==NULL)return NULL;
        queue<TreeNode*>q;
        TreeNode*ans=NULL;
        q.push(root);
        mp[root]=NULL;
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            if(front->val==target)ans=front;
            if(front->left){
                mp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right]=front;
                q.push(front->right);
            }
        }
        return ans;
    }
    void solve(TreeNode*root,unordered_map<TreeNode*,TreeNode*>parent,int&ans){
        if(root==NULL)return;
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(root);
        visited[root]=true;
        while(!q.empty()){
            int n=q.size();
            bool flag=0;
            for(int i=0;i<n;i++){
                TreeNode*front=q.front();
                q.pop();
                if(front->left && visited[front->left]==false){
                    visited[front->left]=true;
                    q.push(front->left);
                    flag=1;
                }
                if(front->right && visited[front->right]==false){
                    visited[front->right]=true;
                    q.push(front->right);
                    flag=1;
                }
                if(parent[front] && visited[parent[front]]==false){
                    flag=1;
                    q.push(parent[front]);
                    visited[parent[front]]=true;
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp;
        int count=0;
        TreeNode*ans=mapping(root,start,mp);
        if(ans==NULL)return 0;
        solve(ans,mp,count);
        return count;
    }
};