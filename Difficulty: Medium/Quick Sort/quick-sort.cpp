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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high){
            int index=partition(arr,low,high);
            quickSort(arr,low,index-1);
            quickSort(arr,index+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[low];
       int j=low+1;
       int count=0;
       while(j<=high){
           if(arr[j]<=pivot){
               count++;
           }
           j++;
       }
       int partition=low+count;
       swap(arr[low],arr[partition]);
       int i=low;
       j=high;
       while(i<partition && j>partition){
           while(arr[i]<=pivot){
               i++;
           }
           while(arr[j]>pivot){
               j--;
           }
           if(i<partition && j>partition){
               swap(arr[i++],arr[j--]);
           }
       }
       return partition;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends