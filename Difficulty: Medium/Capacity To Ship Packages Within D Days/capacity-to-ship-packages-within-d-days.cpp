//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(int* weights, int days, long long mid, int n) {
        int mydays = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                sum = weights[i];
                mydays++;
                if (mydays > days) {
                    return false;
                }
            }
        }
        return true;
    }

    int leastWeightCapacity(int weights[], int n, int d) {
        long long sum = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        long long low = maxi, high = sum;
        long long ans = high;  // Initialize ans to high, as a fallback

        while (low <= high) {
            long long mid = low + (high - low) / 2;  // Avoid potential overflow in (low + high)

            if (isPossible(weights, d, mid, n)) {
                ans = mid;
                high = mid - 1;  // Try to find a smaller capacity
            } else {
                low = mid + 1;   // Increase the capacity
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends