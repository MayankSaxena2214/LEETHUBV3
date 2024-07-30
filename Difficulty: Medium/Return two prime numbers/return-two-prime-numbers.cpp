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
        vector<int>ans;
        vector<bool>prime(n+2,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                for(int j=2*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(prime[i] && prime[n-i]){
                ans.push_back(i);
                ans.push_back(n-i);
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
        int N;
        cin >> N;

        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends