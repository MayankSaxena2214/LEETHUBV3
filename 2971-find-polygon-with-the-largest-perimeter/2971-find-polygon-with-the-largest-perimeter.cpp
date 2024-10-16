class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        if(nums.size()<3){
            return -1;
        }
        long long int sum=0;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            sum+=i;
        }
        for(int i=nums.size()-1;i>=2;i--){
            if(sum-nums[i]>nums[i]){
                return sum;
            }
            sum=sum-nums[i];
        }
        return -1;
    }
};