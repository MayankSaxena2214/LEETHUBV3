class Solution {
public:
    string sortSentence(string s) {
        vector<string>v(10);
        string curr;
        for(auto ch:s){
            if(ch==' ')continue;
            if(ch>='0' && ch<='9'){
                v[ch-'0']=curr +" ";
                curr="";
            }
            else{
                curr+=ch;
            }
        }
        string ans;
        for(int i=0;i<10;i++){
            ans+=v[i];
            
        }
        ans.pop_back();
        return ans;

    }
};