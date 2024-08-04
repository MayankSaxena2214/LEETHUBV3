class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0 || n==1)return 0;
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]-mini>profit){
                profit=prices[i]-mini;
            }
            mini=min(prices[i],mini);
        }
        return profit;
    }
};