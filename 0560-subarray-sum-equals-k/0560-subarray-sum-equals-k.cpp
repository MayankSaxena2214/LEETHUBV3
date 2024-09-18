class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int count=0;
        mp[0]=1;
        int  n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            // Check if there is a subarray ending here that sums to k
            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            
            // Update the map with the current sum
            mp[sum]++;
        }
        return count;
    }
};