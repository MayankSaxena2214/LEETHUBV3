class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0)return 0;
        int start=0,end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return 2;
            }
            start++;
            end--;
        }
        return 1;
    }
};