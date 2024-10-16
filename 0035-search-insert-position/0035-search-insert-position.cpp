class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            int val=nums[mid];
            if(val==target){
                return mid;
            }
            else if(val>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};