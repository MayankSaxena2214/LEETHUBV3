class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(auto val:nums){
            if(st.find(val-1)==st.end()){
                int count=0;
                while(st.find(val)!=st.end()){
                    count++;
                    val++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};