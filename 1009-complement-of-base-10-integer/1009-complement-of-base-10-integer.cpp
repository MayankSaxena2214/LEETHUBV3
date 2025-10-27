class Solution {
public:
    int bitwiseComplement(int n) {
        int mask=0;
        int x=n;
        while(x!=0){
            mask=(mask<<1)|1;
            x=x>>1;
        }
        return (~n)&mask;
    }
};