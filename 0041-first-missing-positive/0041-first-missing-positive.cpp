class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        //our concerned elements will be [1,n]
        for(int i=0;i<n;i++){
            if(nums[i]>=1 && nums[i]<=n){
                int curr=nums[i];
                int pos=curr-1;
                if(nums[pos]!=curr){
                    swap(nums[pos],nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};