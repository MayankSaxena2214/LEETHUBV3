class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(val!=0)swap(nums[k++],nums[i]);
        }
       
    }
};