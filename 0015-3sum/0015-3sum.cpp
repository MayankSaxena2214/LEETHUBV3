class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int low=i+1;
            int high=n-1;
            while(low<high){
                int val=nums[i]+nums[low]+nums[high];
                if(val==0){
                    ans.insert({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                }
                else if(val>0){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        vector<vector<int>>result(ans.begin(),ans.end());
        return result;
    }
};