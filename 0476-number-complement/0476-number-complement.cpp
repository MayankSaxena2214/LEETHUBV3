class Solution {
public:
    int findComplement(int num) {
        int m=num;
        int buff=0;
        while(m!=0){
            buff=(buff<<1)|1;
            m=m>>1;
        }

        return (~num)&buff;
    }
};