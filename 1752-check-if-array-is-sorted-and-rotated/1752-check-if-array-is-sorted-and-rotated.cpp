class Solution {
public:
    bool check(vector<int>& nums) {
        //next element smaller count
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i])count++;
        }
        if(nums[n-1]>nums[0]){
            count++;
        }
        return count<=1;
    }
};