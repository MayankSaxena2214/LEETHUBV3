class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n);
        int sum=0;
        for(int i=n-1;i>=0;i--){
            suffix[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=0;i<n;i++){
            if(sum==suffix[i]){
                return i;
            }
            sum+=nums[i];
        }
        return -1;
    }
};