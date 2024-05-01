class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int> > res;
        if(nums.size()<3){
            return ans;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                if(nums[s]+nums[e]==-nums[i]){
                    res.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]>=-nums[i]){
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
};