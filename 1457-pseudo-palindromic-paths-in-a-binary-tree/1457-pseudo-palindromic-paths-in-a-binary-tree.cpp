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
    void solve(auto&root,auto&ans,auto&v){
        if(root==NULL)return;
        v[root->val]++;
        solve(root->left,ans,v);
        solve(root->right,ans,v);
        if(root->left==NULL && root->right==NULL){
            int oddcnt=0;
            for(int i=1;i<=9;i++){
                if(v[i]%2!=0)oddcnt++;
            }
            if(oddcnt<=1)ans++;
        }

        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        int ans=0;
        solve(root,ans,v);
        return ans;
    }
};