class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        map<int,int>mp;
        mp[0]=-1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)count-=1;
            else count+=1;
            if(mp.find(count)==mp.end()){
                mp[count]=i;
            }
            else{
                ans=max(ans,i-mp[count]);
            }
        }
        return ans;
    }
};