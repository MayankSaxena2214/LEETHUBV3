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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)return 0;
        //find level 
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*front=q.front();
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);

            }
            level++;
        }
        int count=0;
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty()){
            int n=q1.size();
            if(count==level-1)break;
            for(int i=0;i<n;i++){
                TreeNode*front=q1.front();
                q1.pop();
                if(front->left)q1.push(front->left);
                if(front->right)q1.push(front->right);

            }
            count++;
            
        }
        int sum=0;
        while(!q1.empty()){
            sum+=q1.front()->val;
            q1.pop();
        }
        return sum;
    }
};