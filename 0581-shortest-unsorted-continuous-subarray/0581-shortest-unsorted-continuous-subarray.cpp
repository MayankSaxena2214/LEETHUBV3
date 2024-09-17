class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        int n=nums.size();
        if(n<=1)return 0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]>nums[i+1]){
                    if(mini>nums[i]){
                        mini=nums[i];
                    }
                    if(maxi<nums[i]){
                        maxi=nums[i];
                    }
                }
            }
            else if(i==n-1){
                if(nums[i]<nums[i-1]){
                    if(mini>nums[i]){
                        mini=nums[i];
                    }
                    if(maxi<nums[i]){
                        maxi=nums[i];
                    }
                }
            }
            else{
                if(nums[i]>nums[i+1] || nums[i]<nums[i-1]){
                    if(mini>nums[i]){
                        mini=nums[i];
                    }
                    if(maxi<nums[i]){
                        maxi=nums[i];
                    }
                }
            }
        }
        if(mini==INT_MAX || maxi==INT_MIN){
            return 0;
        }
        int i;
        for(i=0;i<n && nums[i]<=mini;i++){}
        int j;
        for(j=n-1;j>=0 && nums[j]>=maxi;j--){}
        return j-i+1;

    }
};