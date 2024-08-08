class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            continue;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            s[i]=tolower(s[i]);
        }
        else if(s[i]>='0' && s[i]<='9'){
            continue;
        }
        else{
            s.erase(i,1);
            i--;
        }
    }
    // cout<<s<<endl;
    int start=0,end=s.length()-1;
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++,end--;
    }
    return true;
    }
};