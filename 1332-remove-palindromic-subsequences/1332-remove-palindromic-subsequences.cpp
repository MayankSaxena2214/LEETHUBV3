class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0)return 0;
        string rev=s;
        reverse(rev.begin(),rev.end());
        if(s==rev)return 1;
        return 2;
    }
};