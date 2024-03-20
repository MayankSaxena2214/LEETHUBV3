class Solution {
public:
    int getPivot(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    int bs(vector<int> nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
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
        if(nums.size()==1 && nums[0]==target)return 0;
        if(nums.size()==1 && nums[0]!=target)return -1;
        int index=getPivot(nums);
        if(target>=nums[0] && target<=nums[index-1]){
            return bs(nums,0,index-1,target);
        }
        else{
            return bs(nums,index,nums.size()-1,target);
        }
    }
};