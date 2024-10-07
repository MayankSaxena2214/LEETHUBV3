class Solution {
public:
    int firstOccur(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                ans=mid;
                e--;
            }
            else if(nums[mid]>target)e--;
            else s++;
        }
        return ans;
    }
    int lastOccur(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                ans=mid;
                s++;
            }
            else if(nums[mid]>target)e--;
            else s++;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccur(nums,target);
        int last=lastOccur(nums,target);
        return {first,last};
    }
};