class Solution {
public:
    int reverse(int x) {
        int m=x;
        int ans=0;
        while(m){
            int digit=m%10;
            if(ans<INT_MIN/10 || ans>INT_MAX/10)return -1;
            ans=ans*10+digit;
            m=m/10;
        }
        return ans;
    }
};