class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z')continue;
            else if(s[i]>='0' && s[i]<='9')continue;
            else if(s[i]>='A' && s[i]<='Z'){
                int jump=s[i]-'A';
                s[i]=jump+'a';
            }
            else{
                s.erase(i,1);
                i--;
            }
        }
        for(auto ch:s)cout<<ch;
        int low=0,high=s.length()-1;
        while(low<high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};