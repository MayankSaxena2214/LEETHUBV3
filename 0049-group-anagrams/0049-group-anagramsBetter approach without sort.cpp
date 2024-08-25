class Solution {
public:
    string generate(string str){
        string ans;
        // cout<<"str="<<str<<endl;
        vector<int>v(26,0);
        for(auto val:str){
            // cout<<"val="<<val<<endl;
            // cout<<"index="<<val-'a'<<endl;
            v[val-'a']++;

        }
        for(int i=0;i<26;i++){
            while(v[i]!=0){
                ans+=i+'a';
                v[i]--;
            }
        }
        // cout<<"ans="<<ans<<endl;
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto str:strs){
            string temp=generate(str);
            mp[temp].push_back(str);
        }
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};