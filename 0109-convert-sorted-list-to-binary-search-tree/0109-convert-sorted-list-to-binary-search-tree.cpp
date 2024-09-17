/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(auto&arr,int start,int end,int n){
        if(start>end)return NULL;
        int mid=(start+end)/2;
        TreeNode*root=new TreeNode(arr[mid]);
        root->left=solve(arr,start,mid-1,n);
        root->right=solve(arr,mid+1,end,n);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        return solve(arr,0,n-1,n);
    }
};