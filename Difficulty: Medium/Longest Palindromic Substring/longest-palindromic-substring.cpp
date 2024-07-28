//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        int n=s.length();
        int maxi=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(n,0));
        string ans;
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=i+diff;i<n && j<n;i++,j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(diff==1){
                    if(s[i]==s[j]){
                        dp[i][j]=2;
                    }
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]){
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

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends