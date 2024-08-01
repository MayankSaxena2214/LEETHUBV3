class Solution {
public:
    void solve(auto&nums,auto&ans,int index,int n){
        if(index==n){
            ans.insert(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            solve(nums,ans,index+1,n);
            swap(nums[i],nums[index]);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        int index=0;
        int n=nums.size();
        solve(nums,ans,index,n);
        vector<vector<int>>v(ans.begin(),ans.end());
        return v;
    }
};