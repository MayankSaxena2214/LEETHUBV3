//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int binarySearch(vector<int>&arr,int n,int target,int s,int e){
    int mid=(s+e)/2;
    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return -1;
}
int getPivot(vector<int>&arr,int n){
    int s=0,e=n-1;
    int mid=(s+e)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=(s+e)/2;
    }
    return s;
}
    int search(vector<int>& arr, int k) {
        // complete the function here
        int n=arr.size();
        int pivotIndex=getPivot(arr,n);
    if(k>=arr[0] && k<=arr[pivotIndex-1]){
        return binarySearch(arr,n,k,0,pivotIndex-1);
    }
    else{
        return binarySearch(arr,n,k,pivotIndex,n-1);
    }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends