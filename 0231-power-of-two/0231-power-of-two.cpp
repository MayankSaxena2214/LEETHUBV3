class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans=1;
        for(int i=0;i<31;i++){
            ans=pow(2,i);
            if(ans==n)return true;
        }
        return false;

    }
};