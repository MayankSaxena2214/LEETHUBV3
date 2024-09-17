//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeDivision(int n) {
        // code here
        vector<bool>prime(n+1,true);
        for(int i=2;i*i<n;i++){
            if(prime[i]){
                for(int j=2*i;j<n;j+=i){
                    prime[j]=false;    
                }        
            }
        }
        for(int i=2;i<n;i++){
            if(prime[i] && prime[n-i])return {i,n-i};
        }
        return {};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends