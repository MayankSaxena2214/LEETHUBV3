class Solution {
public:
 int findLastOccur(auto&nums,int&target,int n){
        //
        int s=0,e=n-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
               s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;

    }
    int findFirstOccur(auto&nums,int&target,int n){
        //
        int s=0,e=n-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirstOccur(nums,target,nums.size());
        int last=findLastOccur(nums,target,nums.size());
        return {first,last};
    }
};