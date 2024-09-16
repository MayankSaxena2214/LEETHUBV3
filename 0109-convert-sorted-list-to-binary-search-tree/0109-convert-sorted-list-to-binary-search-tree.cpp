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
    TreeNode*solve(int start,int end,auto&arr,int n){
        if(start>end)return NULL;
        int mid=start+(end-start)/2;
        int element=arr[mid];
        TreeNode*root=new TreeNode(element);
        root->left=solve(start,mid-1,arr,n);
        root->right=solve(mid+1,end,arr,n);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ans;
        ListNode*temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        return solve(0,n-1,ans,n);
    }
};