class Solution {
public:
    bool isPossible(vector<int>&weights,int days,int mid){
        int mydays=1;
        long long int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }
            else{
                sum=weights[i];
                mydays++;

            }
        }
        if(mydays<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long int low=*max_element(weights.begin(),weights.end());
        long long int high=accumulate(weights.begin(),weights.end(),0);
        long long int ans=-1;
        while(low<high){
            long long int mid=(low+high)/2;
            if(isPossible(weights,days,mid)){
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