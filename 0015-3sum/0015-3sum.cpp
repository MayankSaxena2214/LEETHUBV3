class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                int val=nums[i]+nums[s]+nums[e];
                if(val==0){
                    temp.insert({nums[i],nums[s],nums[e]});
                    s++,e--;
                }
                else if(val>0){
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        vector<vector<int>>ans(temp.begin(),temp.end());
        return ans;
    }
};