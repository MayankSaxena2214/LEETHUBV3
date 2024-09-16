class Solution {
public:
    string generate(string str){
        string ans;
        vector<int>v(26,0);
        for(auto ch:str){
            v[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            while(v[i]>0){
                char ch=i+'a';
                cout<<ch<<"Index is "<<i<<endl;
                ans+=ch;
                v[i]--;
            }
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>mp;
        for(auto str:strs){
            string sorted=generate(str);
            cout<<sorted<<endl;
            mp[sorted].push_back(str);

        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};