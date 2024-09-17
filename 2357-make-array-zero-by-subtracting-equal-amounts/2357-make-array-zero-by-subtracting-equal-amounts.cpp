class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>st;
        for(auto val:nums){
            if(val!=0){
                st.insert(val);
            }
        }
        return st.size();
    }
};