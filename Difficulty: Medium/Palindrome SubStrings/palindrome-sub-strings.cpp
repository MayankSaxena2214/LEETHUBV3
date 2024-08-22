//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // int CountPS(char s[], int n);

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
// int N;
// cin >> N;
// char S[N + 1];
// cin >> S;
// Solution ob;
//         cout << ob.CountPS(S, N) << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int CountPS(char s[], int n) {
        // code here
         int count=0;
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=diff;i<n,j<n;i++,j++){
                if(diff==0){
                    dp[i][j]=true;
                }
                else if(diff==1){
                    dp[i][j]=s[i]==s[j];
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                if(j-i+1>=2)
                if(dp[i][j])count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        char S[N + 1];
        cin >> S;
        Solution ob;
        cout << ob.CountPS(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends