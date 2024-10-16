class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag=0;
        int len=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if(len>0)return len;
            }
            else{
                len++;
            }
        }
        return len;
    }
};