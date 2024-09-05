class Solution {
public:
    string longestPalindrome(string s) {
        
        string ans;
        int maxi=INT_MIN;
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=i+diff;i<n&&j<n;i++,j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(diff==1){
                    if(s[i]==s[j]){
                        dp[i][j]=2;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]!=0){
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                    if(j-i+1>maxi){
                        maxi=j-i+1;
                        ans=s.substr(i,maxi);
                    }
                }
            }
        }
        return ans;
    }
};