//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int nums[], int n, int x) {
        // Your Code Here
         sort(nums,nums+n);
        
        
        for(int i=0;i<n;i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                int val=nums[i]+nums[s]+nums[e];
                if(val==x){
                    return true;
                }
                else if(val>x){
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends