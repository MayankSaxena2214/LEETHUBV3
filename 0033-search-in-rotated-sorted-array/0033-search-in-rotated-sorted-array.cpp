class Solution {
public:
    int getPivot(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<e){
            int mid=(s+e)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
    int bs(vector<int>& nums, int target,int s,int e) {
        
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)e--;
            else s++;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivotIndex=getPivot(nums);
        if(nums[pivotIndex]>=nums[0]){
            return bs(nums,target,0,pivotIndex-1);
        }
        else{
            return bs(nums,target,pivotIndex,nums.size()-1);
        }
    }
};