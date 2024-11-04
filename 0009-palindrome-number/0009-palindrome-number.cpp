class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        //reverse the number
        int ans=0;
        int num=x;
        while(num!=0){
            int digit=num%10;
            if(ans>INT_MAX/10)return false;
            ans=ans*10+digit;
            num=num/10;
        }
        return ans==x;
    }
};