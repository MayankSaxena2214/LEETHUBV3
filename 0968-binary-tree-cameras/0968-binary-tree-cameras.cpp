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
    string solve(auto&root,int&ans){
        if(root==NULL)return "ok";
        string left=solve(root->left,ans);
        string right=solve(root->right,ans);
        if(left=="want" || right=="want"){
            ans++;
            return "provide";
        }
        else if(left=="provide" || right=="provide")return "ok";
        else return "want";
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(solve(root,ans)=="want"){
            ans++;
        }
        return ans;
    }
};