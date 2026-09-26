class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        //5 -> 000000101 => 
        int mask=0;
        int x=n;
        while(x!=0){
            mask=(mask<<1)|1;
            x=x>>1;
        }
        int ans=(~n)&mask;
        return ans;
    }
};