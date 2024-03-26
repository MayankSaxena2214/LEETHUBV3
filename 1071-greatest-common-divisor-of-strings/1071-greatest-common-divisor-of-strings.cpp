class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(!(str1+str2==str2+str1)){
            return "";
        }
        int a=str1.length();
        int b=str2.length();
        while(b%a!=0){
            int rem=b%a;
            b=a;
            a=rem;
        }
        return str1.substr(0,a);
    }
};