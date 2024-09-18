class Solution {
public:
    void solve(int index,int target,vector<vector<int>>&ans,vector<int>temp,vector<int>&arr,int n){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || index>=n)return;
        //not take
        solve(index+1,target,ans,temp,arr,n);
        temp.push_back(arr[index]);
        solve(index,target-arr[index],ans,temp,arr,n);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,target,ans,temp,candidates,candidates.size());
        return ans;
    }
};