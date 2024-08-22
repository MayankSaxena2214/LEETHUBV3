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
        for(int i=low;i<=high;i++){
            if(isPossible(weights,days,i)){
                return i;
            }
        }
        return -1;
    }
};
