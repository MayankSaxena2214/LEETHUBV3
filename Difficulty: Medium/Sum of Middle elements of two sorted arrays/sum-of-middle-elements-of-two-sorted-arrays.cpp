//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &nums1, vector<int> &nums2) {
        // code here
        int element1=0,element2=0;
        int i=0,j=0,k=0;
        int n=nums1.size(),m=nums2.size();
        int idx1=(n+m)/2;
        int idx2=idx1-1;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(k==idx1)element1=nums1[i];
            if(k==idx2)element2=nums1[i];
            i++;
            k++;
            }
            else{
                if(k==idx1)element1=nums2[j];
            if(k==idx2)element2=nums2[j];
            j++;
            k++;
            }
        }
        while(i<n){
            if(k==idx1)element1=nums1[i];
            if(k==idx2)element2=nums1[i];
            i++;
            k++;
        }
        while(j<m){
            if(k==idx1)element1=nums2[j];
            if(k==idx2)element2=nums2[j];
            j++;
            k++;
        }
        if((n+m)%2==0){
            return element1+element2;
        }
        return element1;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends