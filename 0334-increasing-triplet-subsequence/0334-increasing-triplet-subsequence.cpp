class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return false;
        vector<int>right(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                right[i]=nums[i];
            }
            else{
                right[i]=max(right[i+1],nums[i]);
            }
        }
        set<int>st;
        st.insert(nums[0]);
        for(int i =1;i<n;i++){
            st.insert(nums[i]);
            auto it=st.find(nums[i]);
            if(it!=st.begin() && right[i]!=nums[i]){
                return true;
            }
        }
        return false;
    }
};