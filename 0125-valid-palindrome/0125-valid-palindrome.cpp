class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto ch:s){
            if(ch>='A' && ch<='Z'){
                str.push_back(ch-'A'+'a');
            }
            else if(ch>='a' && ch<='z'){
                str.push_back(ch);
            }
            else if(ch>='0' && ch<='9'){
                str.push_back(ch);
            }
        }
        cout<<str<<" ";
        //check palindrome
        int st=0,e=str.length()-1;
        while(st<e){
            if(str[st++]!=str[e--])return false;
        }
        return true;
    }
};