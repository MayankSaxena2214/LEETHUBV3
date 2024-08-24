//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes here
        int n=nums1.size();
        int m=nums2.size();
        if(n>m)return MedianOfArrays(nums2,nums1);
        
        int l=0,r=n;
        // l denote nums1 element are 1 and right denote nums1 element are n taken
        while(l<=r){
            int Px=(l+(r-l)/2);
            int Py=(m+n+1)/2-Px;
            
            int x1=(Px==0)?INT_MIN:nums1[Px-1];
            int y1=(Py==0)?INT_MIN:nums2[Py-1];
            int x2=(Px==n)?INT_MAX:nums1[Px];
            int y2=(Py==m)?INT_MAX:nums2[Py];
            
            if(x1<=y2 && y1<=x2){
                if((n+m)%2==0){
                    return (max(x1,y1)+min(x2,y2))/2.0;
                }
                else{
                    return max(x1,y1);
                }
            }
            else if(x1>y2){
                //zyada element le liye
                r=Px-1;
            }
            else{
                l=Px+1;
            }
        }
        return -1;
    
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