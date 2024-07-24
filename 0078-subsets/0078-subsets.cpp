class Solution {
public:
    void solve(auto&nums,auto index,auto&ans,auto output){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums,index+1,ans,output);
        output.push_back(nums[index]);
        solve(nums,index+1,ans,output);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int  index=0;
        solve(nums,index,ans,output);
        return ans;
    }
};