//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        vector<int>ans;
        deque<int>pq;
        int n=arr.size();
        for(int i=0;i<k;i++){
            while(!pq.empty() && arr[pq.back()]<=arr[i]){
                pq.pop_back();
            }
            pq.push_back(i);
        }
        ans.push_back(arr[pq.front()]);
        int i=k;
        while(i<n){
            //removal
            if(!pq.empty() && i-pq.front()>=k){
                pq.pop_front();
            }
            //addition
            while(!pq.empty() && arr[pq.back()]<=arr[i]){
                pq.pop_back();
            }
            pq.push_back(i);
            
            ans.push_back(arr[pq.front()]);
            i++;
        }
        return ans;
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
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends