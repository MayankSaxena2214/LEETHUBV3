//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here.
        int i=0;
        int ans=0;
        while(str.length()!=0){
            int bit=str[str.length()-1]=='1'?1:0;
            if(bit==1){
                ans=ans+pow(2,i);
            }
            i++;
            str=str.substr(0,str.length()-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends