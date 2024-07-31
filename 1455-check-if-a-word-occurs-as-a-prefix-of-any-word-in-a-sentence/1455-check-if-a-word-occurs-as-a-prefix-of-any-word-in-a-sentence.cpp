class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count=0;
        string check;
        int n=searchWord.length();
        for(auto ch:sentence){
            if(ch==' '){
                if(check.length()>=n && check.substr(0,n)==searchWord){
                    return count+1;
                }
                else{
                    count++;
                    check="";
                }
            }
            else{
                check+=ch;
            }
        }
        if(check.length()>=n && check.substr(0,n)==searchWord)return count+1;
        return -1;
    }
};