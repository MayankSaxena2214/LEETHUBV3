class Solution {
public:
    string frequencySort(string s) {
        string ans;
        if(s.length()==0)return ans;
        map<char,int>mp;
        for(auto ch:s)mp[ch]++;
        vector<pair<int,char>>v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto i:v){
            int count=i.first;
            while(count>0){
                ans+=i.second;
                count--;
            }
        }
        return ans;
    }
};