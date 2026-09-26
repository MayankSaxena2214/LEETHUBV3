class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for(auto val:arr)mp[val]++;
        for(auto pr:mp)st.insert(pr.second);
        return mp.size()==st.size();
    }
};