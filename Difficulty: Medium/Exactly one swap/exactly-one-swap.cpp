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
        long long n=s.length();
        vector<long long>count(26,0);
        for(long long i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        bool isRepeat=false;
        long long ans=(n*(n-1))/2;
        for(int i =0;i<26;i++){
            if(count[i]>1){
                isRepeat=true;
            }
            ans-=((count[i]*(count[i]-1))/2);
        }
        return isRepeat?ans+1:ans;
        
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