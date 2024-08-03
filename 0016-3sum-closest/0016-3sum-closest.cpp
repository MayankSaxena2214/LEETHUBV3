class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=0;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=n-1;
            int first=nums[i];
            
            while(start<end){
                int data=first+nums[start]+nums[end];
                if(data==target){
                    return data;
                }
                if(abs(nums[start]+nums[end]+first-target)<diff){
                    diff=abs(nums[start]+nums[end]+first-target);
                    ans=nums[start]+nums[end]+first;
                }
                if(data<target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return ans;
    }
};