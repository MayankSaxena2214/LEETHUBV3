/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "x";
        string leftserialize=serialize(root->left);
        string rightserialize=serialize(root->right);
        return to_string(root->val)+" "+leftserialize+" "+rightserialize;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string>v;
        string buff;
        while(ss>>buff){
            v.push_back(buff);
        }
        queue<string>q;
        for(int i=0;i<v.size();i++){
            q.push(v[i]);
        }
        return solve(q);

    }
    TreeNode* solve(queue<string>&q){
        if(q.size()==0){
            return NULL;
        }
        string top=q.front();
        q.pop();
        if(top=="x"){
            return NULL;
        }
        TreeNode*root=new TreeNode(stoi(top));
        root->left=solve(q);
        root->right=solve(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));