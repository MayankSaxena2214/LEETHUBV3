class Solution {
public:
    string sortSentence(string s) {
        vector<string>v(10);
        string curr;
        for(auto ch:s){
            if(ch==' '){
                continue;
            }
            else if(ch>='0' && ch<='9'){
                int index=ch-'0';
                v[index]+=curr+" ";
                curr="";
            }
            else{
                curr+=ch;
            }
        }
        string ans;
        for(auto str:v){
            ans+=str;
        }
        if(ans.length()>0){
            ans.pop_back();
            return ans;
        }
        return ans;
    }
};