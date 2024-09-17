class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1){
            return 1;
        }
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for(auto arr:trust){
            mp[arr[1]]++;
            st.insert(arr[0]);
        }
        for(auto i:mp){
            if(i.second==n-1){
                if(st.find(i.first)==st.end()){
                    return i.first;
                }
            }
        }
        return -1;
    }
};