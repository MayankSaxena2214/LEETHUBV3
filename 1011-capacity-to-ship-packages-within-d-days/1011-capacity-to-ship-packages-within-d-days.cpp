class Solution {
public:
    bool isPossible(auto&weights,int mid,int days){
        int mydays=1;
        long long int sum=0;
        for(auto val:weights){
            if(val+sum<=mid){
                sum+=val;
            }
            else{
                mydays++;
                sum=val;
                if(mydays>days)return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long int low=*max_element(weights.begin(),weights.end());
        long long int high=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(isPossible(weights,mid,days)){
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