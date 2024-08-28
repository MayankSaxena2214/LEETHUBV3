class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int ans=0;
        int mask=0;
        int num=n;
        while(num){
            mask=(mask<<1)|1;
            num=num>>1;
        }
        return (~n)&mask;
    }
};