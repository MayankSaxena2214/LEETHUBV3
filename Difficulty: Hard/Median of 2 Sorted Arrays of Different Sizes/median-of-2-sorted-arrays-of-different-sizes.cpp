//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int element1,element2;
        int k=0;
        int n=array1.size();
        int m=array2.size();
        int idx1=(n+m)/2;
        int idx2=idx1-1;
        int i=0,j=0;
        while(i<n && j<m){
            if(array1[i]<array2[j]){
                if(k==idx1){
                    element1=array1[i];
                }
                if(k==idx2){
                    element2=array1[i];
                }
                i++;
                k++;
            }
            else{
                if(k==idx1){
                    element1=array2[j];
                }
                if(k==idx2){
                    element2=array2[j];
                }
                j++;
                k++;
            }
        }
        while(i<n){
            if(k==idx1){
                    element1=array1[i];
                }
                if(k==idx2){
                    element2=array1[i];
                }
                i++;
                k++;
        }
        while(j<m){
            if(k==idx1){
                    element1=array2[j];
                }
                if(k==idx2){
                    element2=array2[j];
                }
                j++;
                k++;
        }
        if((n+m)%2==0){
            return ((element1+element2)/2.0);
        }
        else {
            return element1;
        }
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends