class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=INT_MIN;
        int life1=0;
        int candidate2=INT_MIN;
        int life2=0;
        for(auto val:nums){
            if(candidate1==val){
                life1++;
            }
            else if(candidate2==val){
                life2++;
            }
            else if(life1==0){
                candidate1=val;
                life1=1;
            }
            else if(life2==0){
                candidate2=val;
                life2++;
            }
            else{
                life1--;
                life2--;
            }
        }
        int freq1=0,freq2=0;
        for(auto val:nums){
            if(val==candidate1)freq1++;
            if(val==candidate2)freq2++;
        }
        vector<int>ans;
        int n=nums.size();
        if(freq1>n/3)ans.push_back(candidate1);
        if(freq2>n/3)ans.push_back(candidate2);
        return ans;
    }
};