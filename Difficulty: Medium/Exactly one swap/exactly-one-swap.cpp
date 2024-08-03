//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string s)
    {
        // code here
        
        long long ans=0;
        long long  n=s.length();
        ans=(n*(n-1))/2;
        vector<long long>v(26,0);
        for(char ch:s){
            v[ch-'a']++;
        }
        bool repeat=false;
        for(int i=0;i<26;i++){
            if(v[i]>1)repeat=true;
            ans-=(v[i]*(v[i]-1))/2;
        }
        return repeat?ans+1:ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends