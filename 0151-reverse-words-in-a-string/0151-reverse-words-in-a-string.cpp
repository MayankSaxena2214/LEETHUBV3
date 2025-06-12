class Solution {
public:
    string reverseWords(string s) {
        string temp;
        vector<string>arr;
        for(auto ch:s){
            if(ch==' '){
                if(temp.length()>0){
                    arr.push_back(temp);
                    temp="";
                }
            }
            else{
                temp+=ch;
            }
        }
        string ans;
        //last string remaining
        if(temp.length()>0){
            arr.push_back(temp);
        }
        for(int i=arr.size()-1;i>=0;i--){
            ans+=arr[i];
            if(i!=0)ans+=' ';
        }
        return ans;

    }
};