class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<string>temp;
        for(auto str:strs){
            // temp.push_back(sort(str.begin(),str.end()));
            
            string sortedstr=str;
            sort(str.begin(),str.end());
            mp[str].push_back(sortedstr);
        }
        vector<vector<string>>ans;
        for(auto&it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};