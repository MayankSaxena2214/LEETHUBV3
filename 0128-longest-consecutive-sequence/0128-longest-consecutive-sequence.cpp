class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>st;
        for(auto val:nums){
            st.insert(val);
        }
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int prev=curr-1;
            if(st.find(prev)==st.end()){
                int count=0;
                while(st.find(curr)!=st.end()){
                    count++;
                    curr++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};