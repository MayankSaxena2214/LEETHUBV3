//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int maxi=0;
        string ans;
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=diff;j<n;j++,i++){
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

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends