class Solution {
public:
    long long int solve(auto & piles,int mid,int h){
        long long int mytime=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0){
                mytime+=piles[i]/mid;
            }
            else{
                mytime+=piles[i]/mid;
                mytime+=1;
            }
        }
        return mytime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low=1;
        long long int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            long long int mid=(low+(high-low)/2);
            long long int time=solve(piles,mid,h);
            if(time<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};