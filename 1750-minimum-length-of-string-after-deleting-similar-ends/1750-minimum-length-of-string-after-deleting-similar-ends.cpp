class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int start=0,end=n-1;
        while(start<end){
            if(s[start]!=s[end]){
                return end-start+1;
            }
            else{
                char ch=s[start];
                while(start<s.length() && s[start]==ch){
                    start++;
                }
                while(end>=0 && s[end]==ch){
                    
                    end--;
                }
            }
        }
        if(start>end)return 0;
        return end-start+1;
    }
};