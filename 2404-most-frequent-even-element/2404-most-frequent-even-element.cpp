class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(auto val:nums){
            if(val%2==0)mp[val]++;
        }
        int maxi=INT_MIN;
        int ans=-1;
        for(auto i:mp){
            if(i.second>maxi){
                maxi=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};