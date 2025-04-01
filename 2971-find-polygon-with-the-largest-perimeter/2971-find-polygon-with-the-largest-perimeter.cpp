class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long total=accumulate(nums.begin(),nums.end(),0*1LL);
        for(int i=n-1;i>=0;i--){
            if(total-nums[i]>nums[i]){
                return total;
            }
            else{
                total-=nums[i];
            }
        }
        return -1;
    }
};