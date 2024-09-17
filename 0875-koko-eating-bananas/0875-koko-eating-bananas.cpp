class Solution {
public:
    long long fnc(auto&piles,int mid){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0){
                time+=piles[i]/mid;
            }
            else{
                time+=piles[i]/mid;
                time+=1;
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1;
        long long high=*max_element(piles.begin(),piles.end());
        long long ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            long long time=fnc(piles,mid);
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