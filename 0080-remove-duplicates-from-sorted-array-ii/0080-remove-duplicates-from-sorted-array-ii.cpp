class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(i+1<nums.size()){
                if(nums[i]==nums[i+1]){
                    flag=1;
                }
                else{
                     if(flag==1){
                    nums[count++]=nums[i];
                    
                }
                nums[count++]=val;
                flag=0;
                }
            }
            else{
                if(flag==1){
                    nums[count++]=nums[i];
                    
                }
                nums[count++]=val;
                flag=0;
            }
        }
        return count;
    }
};