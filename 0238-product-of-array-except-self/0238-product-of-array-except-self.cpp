class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,1);
        int prod=1;
        for(int i=n-1;i>=0;i--){
            suffix[i]=prod;
            prod=prod*nums[i];
        }
        prod=1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(prod*suffix[i]);
            prod=prod*nums[i];
        }
        return ans;
    }
};