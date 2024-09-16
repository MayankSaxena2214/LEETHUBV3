class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string curr;
        int count=0;
        int n=searchWord.length();
        for(auto ch:sentence){
            if(ch==' '){
                if(curr.length()>=n && curr.substr(0,n)==searchWord){
                    return count+1;
                }
                else{
                    curr="";
                    count++;
                }
            }
            else{
                curr+=ch;
            }
        }
        if(curr.length()>=n && curr.substr(0,n)==searchWord){
            return count+1;
        }
        return -1;
    }
};