class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=-1;
        int n=arr.size();
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=arr[mid+1]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};