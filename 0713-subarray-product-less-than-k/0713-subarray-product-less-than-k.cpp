class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int prod=1;
        int left=0;
        int right=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            prod*=nums[right];
            while(prod>=k && left<=right){
                prod/=nums[left];
                left++;
            }
            
            count+=right-left+1;

        }
        
        
        return count;
    }
};