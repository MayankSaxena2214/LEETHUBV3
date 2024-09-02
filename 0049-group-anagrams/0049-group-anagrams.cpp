class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>mp;
        for(auto str:strs){
            string sorted=str;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(str);

        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};