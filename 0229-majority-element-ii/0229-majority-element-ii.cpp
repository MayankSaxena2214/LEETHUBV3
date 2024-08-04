class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=INT_MIN,cand2=INT_MIN;
        int count1=0,count2=0,freq1=0,freq2=0,n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(cand1==nums[i]){
                count1++;
            }
            else if(cand2==nums[i]){
                count2++;
            }
            else if(count1==0){
                cand1=nums[i];
                count1=1;
            }
            else if(count2==0){
                cand2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==cand1)freq1++;
            if(nums[i]==cand2)freq2++;
        }
        if(freq1>n/3)ans.push_back(cand1);
        if(freq2>n/3)ans.push_back(cand2);
        return ans;
    }
};