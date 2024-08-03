//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> printUnsorted(vector<int>& arr) {
        // Code here
        if(arr.size()==1)return {0,0};
        int n=arr.size();
        int maxi=INT_MIN,mini=INT_MAX;
        bool flag=1;
        for(int i=0;i<n;i++){
            if(i==0){
                if(arr[i]>arr[i+1]){
                    flag=0;
                    maxi=max(maxi,arr[i]);
                    mini=min(mini,arr[i]);
                }
            }
            else if(i==n-1){
                if(arr[i]<arr[i-1]){
                    flag=0;
                    maxi=max(maxi,arr[i]);
                    mini=min(mini,arr[i]);
                }
            }
            else{
                if(arr[i]>arr[i+1] || arr[i]<arr[i-1]){
                    flag=0;
                    maxi=max(maxi,arr[i]);
                    mini=min(mini,arr[i]);
                }
            }
        }
        if(flag==1)return {0,0};
        int i,j;
        for(i=0;i<n && arr[i]<=mini;i++){
            
        }
        for(j=n-1;j>=0 && arr[j]>=maxi;j--){}
        return {i,j};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the number of test cases
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends