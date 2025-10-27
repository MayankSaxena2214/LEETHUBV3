class Solution {
public:
    bool isPowerOfTwo(int n) {
        int formed=1;
        for(int i=0;i<31;i++){
            if(n==formed){
                return true;
            }
            if(formed<INT_MAX/2)
            formed=formed*2;
        }
        return false;
    }
};