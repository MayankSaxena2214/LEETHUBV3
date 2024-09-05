class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=diff;i<n, j<n;i++,j++){
                if(diff==0){
                    dp[i][j]=1;
                }
                else if(diff==1){
                    if(s[i]==s[j]){
                        dp[i][j]=2;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]!=0){
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j]!=0){
                    count++;
                }
            }
        }
        return count;
    }
};