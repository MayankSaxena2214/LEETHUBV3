class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int element=nums[i];
            if(element>=1 && element<=n){
                int index=element-1;
                if(nums[index]!=element){
                    swap(nums[index],nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i])return i+1;
        }
        return n+1;
    }
};