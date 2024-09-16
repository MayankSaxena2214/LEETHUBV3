//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int ans=0;
        int n=str.length();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            char ch=str[i];
            if(ch=='('){
                st.push({ch,i});
            }
            else{
                if(!st.empty() && st.top().first=='('){
                    auto top=st.top();
                    char topch=top.first;
                    int topindex=top.second;
                    ans=max(ans,i-topindex+1);
                    st.pop();
                    if(!st.empty()){
                        ans=max(ans,i-st.top().second);
                    }
                    else{
                        ans=max(ans,i+1);
                    }
                }
                else{
                    st.push({ch,i});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends