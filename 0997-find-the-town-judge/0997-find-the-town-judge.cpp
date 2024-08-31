class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++){
            st.insert(trust[i][0]);
            mp[trust[i][1]]++;
        }
        for(auto it:mp){
            if(st.find(it.first)==st.end() && mp[it.first]==n-1){
                return it.first;
            }
        }
        return -1;
    }
};