class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int index=nums[i]%n;
            int val=nums[nums[i]]%n;
            nums[i]=index+(val%n)*n;
        }
        for(int i=0;i<n;i++){
            nums[i]=nums[i]/n;
        }
        return nums;
    }
};