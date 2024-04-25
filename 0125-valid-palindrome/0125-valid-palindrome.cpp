class Solution {
public:
string myfilter(string s){
    string ans;
    for(char ch:s){
        if(ch>='a' && ch<='z'){
            ans.push_back(ch);
        }
        else if(ch>='A' &&  ch<='Z'){
            ans.push_back(ch-'A'+'a');
        }
        else if(ch>='0' && ch<='9'){
            ans.push_back(ch);
        }
    }
    return ans;
}
    bool isPalindrome(string s) {
         string filter=myfilter(s);
    int st=0;
    int e=filter.length()-1;
    while(st<e){
        if(filter[st]!=filter[e]){
            return false;
        }
        st++;
        e--;
    }
    return true;
        // string temp;

        // for(int i=0;i<s.length();i++){
        //     char ch=s[i];
        //     if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        //         temp.push_back(ch);
        //     }
        // }
        // if(temp.length()==0){
        //     return true;
        // }
        // // To lower case
        // for(int i=0;i<temp.length();i++){
        //     char ch=temp[i];
        //     if((ch>='a' && ch<='z')  || (ch>='0' && ch<='9')){
        //         temp[i]=temp[i];
        //     }
        //     else{
        //         temp[i]=ch-'A'+'a';
        //     }
        // }
        // int start=0;
        // int end=temp.length()-1;
        // while(start<end){
        //     if(temp[start]!=temp[end]){
        //         return false;
        //     }
        //     start++;
        //     end--;
        // }
        // return true;

    }
};