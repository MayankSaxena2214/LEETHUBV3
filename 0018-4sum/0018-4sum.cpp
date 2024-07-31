class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<4){
            return ans;
        }
        set<vector<int>> res;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int ith=nums[i];
                int jth=nums[j];
                int start=j+1;
                int end=n-1;
                long long more=target;
                more=more-ith;
                more=more-jth;
                while(start<end){
                    long long value=nums[start]+nums[end];
                    if(value==more){
                        res.insert({ith,jth,nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if(value<more){
                        start++;
                    }
                    else
                        end--;
                }
            }
        }
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
};