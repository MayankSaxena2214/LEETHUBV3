/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int balance=0;
        int deficient=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficient+=balance;
                start=i+1;
                balance=0;
            }
            
        }
        if(balance+deficient>=0){
            return start;
        }
        return -1;
    }
};