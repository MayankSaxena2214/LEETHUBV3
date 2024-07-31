class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>temp;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int s=j+1,e=n-1;
                long long more=target-nums[i];
                more-=nums[j];
                while(s<e){
                    long long val=nums[s]+nums[e];
                    if(val==more){
                        temp.insert({nums[i],nums[j],nums[s++],nums[e--]});
                    }
                    else if(val>more){
                        e--;
                    }
                    else {
                        s++;
                    }
                }
            }
        }
        vector<vector<int>>ans(temp.begin(),temp.end());
        return ans;
    }
};