//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
     int start=0,end=0;
        int ans=0;
        set<char>st;
        while(start<s.length()){
            char ch=s[start];
            if(st.find(ch)==st.end()){
                st.insert(ch);
                start++;
                ans=max(ans,start-end);
            }
            else{
                //remove the character pointed by e
                char rem=s[end];
                st.erase(rem);
                end++;
            }
        }
        return ans;
}