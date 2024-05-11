//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long solve(long long n){
      if(n<=1){
          return 1;
      }
      if(n%2==0){
          return pow(n,1/2);
      }
      else{
          return pow(n,3/2);
      }
  }
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long>ans;
        if(n<=1){
            return {1};
        }
        ans.push_back(n);
        long long first=n;
        while(n!=1){
            if(n%2==0){
                n=sqrt(n);
                
            }
            else{
                n=n*sqrt(n);
            }
            ans.push_back(n);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends