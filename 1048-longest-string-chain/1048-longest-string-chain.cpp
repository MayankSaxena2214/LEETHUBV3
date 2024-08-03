class Solution {
public:
static bool sortByLength(string a, string b){
    return a.length() < b.length();
}
    int longestStrChain(vector<string>& words) {
        int ans=INT_MIN;
        map<string,int>dp;
        sort(words.begin(),words.end(),sortByLength);
        for(int i=0;i<words.size();i++){
            string word=words[i];
            for(int j=0;j<word.length();j++){
                string pred=word.substr(0,j)+word.substr(j+1);
                dp[word]=max(dp[word],dp[pred]+1);
            }
            
                ans=max(ans,dp[word]);
            
        }
        return ans;
    }
};