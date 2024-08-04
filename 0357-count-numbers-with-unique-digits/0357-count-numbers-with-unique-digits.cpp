class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        int ans=10;
        int start=9;
        int temp=9;
        while(n-1>0 && start){
            temp=temp*start;
            start--;
            ans+=temp;
            n--;
        }
        return ans;
    }
};