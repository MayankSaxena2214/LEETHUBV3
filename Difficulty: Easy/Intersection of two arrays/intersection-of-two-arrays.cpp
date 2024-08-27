//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int nums1[], int nums2[], int n, int m) {
        // Your code goes here
        sort(nums1,nums1+n);
        sort(nums2,nums2+m);
        int i=0,j=0;
        int count=0;
        int size1=n,size2=m;
        while(i<size1 && j<size2){
            if(nums1[i]==nums2[j]){
                count++;
                int curr=nums1[i];
                while(i<size1 && nums1[i]==curr){
                    i++;
                }
                while(j<size2 && nums2[j]==curr){
                    j++;
                }
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends