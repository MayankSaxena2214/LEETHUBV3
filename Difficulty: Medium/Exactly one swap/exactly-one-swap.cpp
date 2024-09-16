//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
        vector<long long>v(26,0);
        long long n=S.length();
        for(int i=0;i<S.length();i++){
            v[S[i]-'a']++;
        }
        long long ans=(n*(n-1))/2;
        bool flag=false;
        for(int i=0;i<26;i++){
            if(v[i]>1){
                flag=true;
            }
            ans-=((v[i]*(v[i]-1))/2);
        }
        if(flag) return ans+1;
        return ans;
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