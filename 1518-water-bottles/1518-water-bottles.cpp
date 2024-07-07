class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            numBottles=numBottles-numExchange;
            numBottles+=1;
            ans+=1;
        }
        return ans;
    }
};