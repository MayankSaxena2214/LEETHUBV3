class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i+1<n){
                if(nums[i]==nums[i+1]){
                    continue;
                }
                else{
                    nums[count++]=nums[i];
                }
            }
            else{
                nums[count++]=nums[i];
            }
        }
        return count;
    }
};