//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int len1=m-l+1;
         int len2=r-m;
         int*first=new int[len1];
         int*second=new int[len2];
         int k=l;
         for(int i=0;i<len1;i++){
             first[i]=arr[k++];
         }
         for(int i=0;i<len2;i++){
             second[i]=arr[k++];
         }
         k=l;
         int i=0,j=0;
         while(i<len1 && j<len2){
             if(first[i]<second[j]){
                 arr[k++]=first[i++];
             }
             else{
                 arr[k++]=second[j++];
             }
         }
         while(i<len1){
             arr[k++]=first[i++];
         }
         while(j<len2){
             arr[k++]=second[j++];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int  mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends