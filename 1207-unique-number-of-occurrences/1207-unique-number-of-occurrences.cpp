class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto val:arr){
            mp[val]++;
        }
        unordered_set<int>st;
        for(auto val:mp){
            st.insert(val.second);
        }
        return mp.size()==st.size();
    }
};