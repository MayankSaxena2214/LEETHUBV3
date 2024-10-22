//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findSubArraySum(int k, vector<int> &arr) {
        // code here
        int sum=0;
        int count=0;
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.findSubArraySum(k, arr);
        cout << res << endl;
        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends