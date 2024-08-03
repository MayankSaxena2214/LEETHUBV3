//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool sortByLength(string a, string b){
    return a.length() < b.length();
}
    int longestChain(int n, vector<string>& words) {
        // Code here
        int ans=INT_MIN;
        unordered_map<string,int>dp;
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends