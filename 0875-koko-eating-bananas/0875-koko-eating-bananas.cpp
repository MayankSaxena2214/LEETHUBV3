class Solution {
public:
    long long int solve(auto&piles,int h,long long int mid){
        
        long long int ans=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0){
                ans+=piles[i]/mid;
            }
            else{
                ans+=piles[i]/mid;
                ans+=1;
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low=1;
        long long int high=*max_element(piles.begin(),piles.end());
        // sort(piles.begin(),piles.end());
        long long int ans=-1;
        while(low<=high){
            long long int mid=(low+high)/2;
            long long int time=solve(piles,h,mid);
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