class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int avg=nums[n/2];
        int ans=0;
        for(auto val:nums){
            cout<<abs(val-avg)<<endl;
            ans+=abs(val-avg);
        }
        return ans;
    }
};