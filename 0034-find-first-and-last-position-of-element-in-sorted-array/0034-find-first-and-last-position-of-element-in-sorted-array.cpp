class Solution {
public:
    int firstOccur(auto&nums,auto&target,int&n){
        int ans=-1;
        int low=0,high=n-1;
        int mid=(low+(high-low)/2);

        while(low<=high){
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=(low+(high-low)/2);
            
        }
        return ans;
    }
    int lastOccur(auto&nums,auto&target,int&n){
        int ans=-1;
        int low=0,high=n-1;
        int mid=(low+(high-low)/2);

        while(low<=high){
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=(low+(high-low)/2);
            
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstOccur(nums,target,n);
        int last=lastOccur(nums,target,n);

        return {first,last};
    }
};