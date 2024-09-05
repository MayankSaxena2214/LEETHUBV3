class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count=0;
        bool firstOne=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){

                if(firstOne){
                    firstOne=false;
                    count=0;
                    continue;
                }
                if(count<k)return false;
                count=0;
            }
            else{
                count++;
            }
        }
        return true;
    }
};