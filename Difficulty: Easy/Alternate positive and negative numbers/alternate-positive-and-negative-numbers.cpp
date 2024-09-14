//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;
        int n = arr.size();

        // Separate the array into positive and negative numbers
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }

        int i = 0, p = 0, q = 0;
        
        // Alternate between positive and negative numbers
        while (p < pos.size() && q < neg.size()) {
            arr[i++] = pos[p++];
            arr[i++] = neg[q++];
        }

        // If there are remaining positive numbers
        while (p < pos.size()) {
            arr[i++] = pos[p++];
        }

        // If there are remaining negative numbers
        while (q < neg.size()) {
            arr[i++] = neg[q++];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends