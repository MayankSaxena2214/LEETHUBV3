class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //brute force
        set<pair<int,int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])==k){
                    //we are not pushing it directly as st.insert({nums[i],nums[j]}) because from this logic the
                    // pair 1,2 and 2,1 will be treated as different but they are actually same
                    int mini=min(nums[i],nums[j]);
                    int maxi=max(nums[i],nums[j]);
                    st.insert({mini,maxi});
                }
            }
        }
        return st.size();
    }
};