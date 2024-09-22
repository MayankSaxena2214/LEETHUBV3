//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        //comparing string with another string takes o(n) time complexity.whereas comparing two numbers take time complexity as o(1).
        //so need to convert the string into some kind of number!!.
        //dont exactly take map length as 26 there might be collisions take a prime number nearest to it!
        int n=str.size();
        if(n==1) return 0;
        const int p=31;
        const int mod=1e9+7;
        int ans=0;
        int i=0,j=n-1;
        long long prefix=0,suffix=0;
        long long pow=1;
        while(i<n-1 && j>0) {
            prefix=(prefix*p+(str[i]-'a'+1)+mod)%mod;
            suffix=(suffix+(str[j]-'a'+1)*pow+mod)%mod;
            pow=(pow*p+mod)%mod;
            if(prefix==suffix) ans=i+1;
            i++;
            j--;
        }
        return ans;
     }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends