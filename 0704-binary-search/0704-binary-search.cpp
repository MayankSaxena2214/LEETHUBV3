class Solution {
public:
int binarySearch(vector<int>arr,int s,int e,int k){
   
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
        
    }
};