class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        int first=-1;
        int second=-1;
        while(s<=e){
            if(nums[mid]==target){
                first=mid;
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
        s=0;
        e=n-1;
        mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                second=mid;
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
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};