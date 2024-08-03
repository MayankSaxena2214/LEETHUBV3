//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                left[i]=arr[i];
            }
            else{
                left[i]=max(left[i-1],arr[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                right[i]=arr[i];
            }
            else{
                right[i]=max(right[i+1],arr[i]);
            }
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans+=min(left[i],right[i])-arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends