class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(auto val:arr){
            mp[val]++;
        }
        for(auto it:mp){
            st.insert(it.second);
        }
        return st.size()==mp.size();
    }
};