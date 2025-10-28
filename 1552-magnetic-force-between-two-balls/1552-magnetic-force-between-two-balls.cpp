class Solution {
public:
    bool isPossible(auto&nums,auto&m,auto&n,auto&mid){
        int lastPos=nums[0];
        int count=1;

        for(int i=0;i<n;i++){
            if(nums[i]-lastPos>=mid){
                count++;
                lastPos=nums[i];
                if(count>=m)return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=0;
        int maxi=position[n-1];
        int mini=position[0];

        int high=maxi-mini;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(isPossible(position,m,n,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};