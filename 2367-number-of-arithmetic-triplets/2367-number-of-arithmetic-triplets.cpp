class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-diff)!=st.end() && st.find(nums[i]-2*diff)!=st.end()){
                ans++;
            }
        }
        return ans;
    }
};