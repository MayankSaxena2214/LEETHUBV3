//{ Driver Code Starts
#include <iostream>
#include <limits.h>
#include <sstream>
#include <vector>

using namespace std;


// } Driver Code Ends


#include<bits/stdc++.h>
class Solution {
  public:
    // Function to find the maximum triplet sum in the array.
    int maxTripletSum(vector<int> &arr) {
        // Complete the function
        int n=arr.size();
        if(n<3)return -1;
        sort(arr.begin(),arr.end());
        return arr[n-3]+arr[n-2]+arr[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob; // Move the class instantiation here
        cout << ob.maxTripletSum(nums) << "\n";
    }
    return 0;
}

// } Driver Code Ends