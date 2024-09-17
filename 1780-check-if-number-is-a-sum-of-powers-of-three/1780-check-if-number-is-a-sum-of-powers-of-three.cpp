class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i=14;i>=0;i--){
            int num=pow(3,i);
            if(n-num>=0){
                n=n-num;
            }
            if(n==0)return true;

        }
        return false;
    }
};