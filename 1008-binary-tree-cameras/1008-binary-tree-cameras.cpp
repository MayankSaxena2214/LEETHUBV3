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
int ans=0;
string solve(TreeNode*root){
    if(root==NULL)return "ok";
    string left=solve(root->left);
    string right=solve(root->right);
    if(left=="want" || right=="want"){
        ans++;
        return "provide";
    }
    else if(left=="provide" || right=="provide"){
        return "ok";
    }
    else return "want";
}

    int minCameraCover(TreeNode* root) {
        if(solve(root)=="want"){
        ans++;
        return ans;
    }
    else{
        return ans;
    }
    }
};