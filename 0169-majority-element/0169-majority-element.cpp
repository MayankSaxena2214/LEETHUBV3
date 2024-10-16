class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int life=0;
        int candidate=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==candidate){
                life++;
            }
            else if(life==0){
                candidate=nums[i];
                life++;
            }
            else{
                life--;
            }
        }
        return candidate;
    }
};