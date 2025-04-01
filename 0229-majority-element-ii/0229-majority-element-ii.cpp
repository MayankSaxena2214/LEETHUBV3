class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=0,cand2=0,life1=0,life2=0;
        int n=nums.size();
        for(auto val:nums){
            if(cand1==val){
                life1++;
            }
            else if(cand2==val){
                life2++;
            }
            else if(life1==0){
                cand1=val;
                life1++;
            }
            else if(life2==0){
                cand2=val;
                life2++;
            }
            else{
                life1--;
                life2--;
            }
        }
        int count1=0,count2=0;
        //check exist or not
        for(int i=0;i<n;i++){
            if(nums[i]==cand1)count1++;
            if(nums[i]==cand2)count2++;
        }
        vector<int>ans;
        if(count1>n/3){
            ans.push_back(cand1);

        }
        if(count2>n/3){
            if(ans.size()>0 && ans.back()!=cand2)
            ans.push_back(cand2);

        }
        return ans;
    }
};