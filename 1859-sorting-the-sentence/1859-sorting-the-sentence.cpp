class Solution {
public:
    string sortSentence(string s) {
        vector<string>v(10);
        string ans;
        string curr;
        for(auto ch:s){
            if(ch==' '){
                continue;
            }
            if(ch>='0' && ch<='9'){
                v[ch-'0']=curr;
                curr="";
            }
            else{
                curr+=ch;
            }
        }
        for(auto str:v){
            if(str.empty())continue;
            ans+=str;
            ans+=" ";
        }
        if(ans.length()>0){
            ans.pop_back();
        }
        return ans;
    }
};