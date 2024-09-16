class Solution {
public:
    static bool custom(string a,string b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        map<string,int>dp;
        int ans=0;
        sort(words.begin(),words.end(),custom);
        for(auto word:words){
            for(int i=0;i<word.length();i++){
                string pred=word.substr(0,i)+word.substr(i+1);
                dp[word]=max(dp[word],dp[pred]+1);
            }
            ans=max(ans,dp[word]);
        }
    return ans;
    }
};