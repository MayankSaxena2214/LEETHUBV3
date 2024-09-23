//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int missing=0,twice=0;
        for(int i=0;i<n;i++){
            int element=arr[i];
            if(element>=1 && element<=n){
                int index=element-1;
                if(arr[index]!=element){
                    swap(arr[index],arr[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                missing=i+1;
                twice=arr[i];
            }
        }
        return {twice,missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends