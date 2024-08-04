class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=1;i<nums.size();i++){
            int val=nums[i]+nums[i-1];
            if(st.find(val)!=st.end()){
                return true;
            }
            else{
                st.insert(val);
            }
        }
        return false;
    }
};