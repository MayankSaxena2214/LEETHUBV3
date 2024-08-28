//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &nums) {
        // Your code here
        int n=nums.size();
        vector<long long>suffix(n);
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            suffix[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=0;i<n;i++){
            if(sum==suffix[i]){
                return i+1;
            }
            sum+=nums[i];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends