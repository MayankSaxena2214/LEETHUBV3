class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=INT_MIN;
        int life=0;
        for(auto val:nums){
            if(candidate==val){
                life++;
            }
            else if(life==0){
                candidate=val;
                life=1;
            }
            else{
                life--;
            }
        }
        return candidate;
    }
};