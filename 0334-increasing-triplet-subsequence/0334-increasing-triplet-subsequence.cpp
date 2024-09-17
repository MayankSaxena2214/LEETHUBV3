class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,0);
        for(int i=n-1;i>=0;i--){
            if(i==n-1)suffix[i]=nums[i];
            else{
                suffix[i]=max(suffix[i+1],nums[i]);
            }
        }
        set<int>st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            st.insert(nums[i]);
            auto it=st.find(nums[i]);
            if(it!=st.begin() && suffix[i]!=nums[i]){
                return true;
            }
        }
        return false;
    }
};