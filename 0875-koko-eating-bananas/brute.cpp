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
        long long int low=1,high=*max_element(piles.begin(),piles.end());
        long long int ans=-1;
        for(int i=low;i<=high;i++){
            long long int time=solve(piles,h,i);
            if(time<=h){
                return i;
            }

        }
        return -1;
    }
};
