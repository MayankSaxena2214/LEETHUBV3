class Solution {
public:
    void solve(int i,auto&ans,auto&temp,int target,auto&arr){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        if(i==arr.size()){
            return;
        }
        solve(i+1,ans,temp,target,arr);
        temp.push_back(arr[i]);
        solve(i,ans,temp,target-arr[i],arr);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,ans,temp,target,candidates);
        return ans;
    }
};