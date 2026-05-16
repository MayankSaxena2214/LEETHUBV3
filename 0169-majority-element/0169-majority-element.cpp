class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,cand=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                cand=nums[i];
                count++;
            }
            else if(cand!=nums[i]){
                count--;
            }
            else{
                count++;
            }
        }   
        return cand;
    }
};