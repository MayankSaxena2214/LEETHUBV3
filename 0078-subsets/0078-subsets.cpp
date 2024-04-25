class Solution {
public:
    void solve(auto&nums,auto index,auto&result,auto&output){
        if(index>=nums.size()){
            result.push_back(output);
            return ;
        }
        solve(nums,index+1,result,output);
        output.push_back(nums[index]);
        solve(nums,index+1,result,output);
        output.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>output;
        int index=0;
        solve(nums,index,result,output);
        return result;
    }
};