class Solution {
public:
    string reverseVowels(string s) {
        string vow="aieouAIEOU";
        deque<char>dq;
        for(auto ch:s){
            if(vow.find(ch)!=string::npos)
                dq.push_back(ch);
        }
        for(int i=0;i<s.length();i++){
            if(vow.find(s[i])!=string::npos){
                s[i]=dq.back();
                dq.pop_back();
            }
        }
        return s;
    }
};