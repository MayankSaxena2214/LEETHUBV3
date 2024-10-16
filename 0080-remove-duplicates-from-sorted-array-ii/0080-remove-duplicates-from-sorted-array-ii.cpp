class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool flag=0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(i+1<n){
                if(nums[i]==nums[i+1]){
                    flag=1;
                }
                else{
                    if(flag==0){
                        nums[count++]=nums[i];
                    }
                    else{
                        nums[count++]=nums[i];
                        nums[count++]=nums[i];
                        flag=0;
                    }
                }
            }
            else{
                if(flag==0){
                        nums[count++]=nums[i];
                    }
                    else{
                        nums[count++]=nums[i];
                        nums[count++]=nums[i];
                        flag=0;
                    }
            }
        }
        return count;
    }
};