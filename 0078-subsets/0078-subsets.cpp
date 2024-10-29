class Solution {
public:
    void solve(auto&nums,auto&temp,auto&ans,int index){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums,temp,ans,index+1);
        temp.push_back(nums[index]);
        solve(nums,temp,ans,index+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(nums,temp,ans,index);
        return ans;
    }
};