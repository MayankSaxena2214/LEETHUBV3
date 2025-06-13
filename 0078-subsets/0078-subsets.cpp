class Solution {
public:
    void solve(auto&ans,auto temp,int index,auto &nums){
        if(index>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //without push
        solve(ans,temp,index+1,nums);
        //withpush
        temp.push_back(nums[index]);
        solve(ans,temp,index+1,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(ans,temp,index,nums);
        return ans;
    }
};