class Solution {
public:
    string replaceDigits(string s) {
        char lastchar;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                lastchar=s[i];
                str+=s[i];
            }
            else{
                str+=lastchar+s[i]-'0';
            }
        }
        return str;
    }
};