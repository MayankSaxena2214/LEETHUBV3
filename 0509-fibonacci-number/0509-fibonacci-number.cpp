class Solution {
public:
    int fib(int n) {
        int f=0;
        int s=1;
        int count=1,t;
        for(int i=0;i<n;i++){
            t=f+s;
            count++;
            if(count==n)return t;
            f=s;
            s=t;
        }
        return n;
    }
};