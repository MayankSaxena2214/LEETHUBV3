class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto word:words){
            map<char,char>mp1;
            map<char,char>mp2;
            bool flag=1;
            for(int j=0;j<word.length();j++){
                if(pattern.length()!=word.length()){
                    flag=0;
                    break;
                }
                auto it1=mp1.find(pattern[j]);
                auto it2=mp2.find(word[j]);
                if(it1==mp1.end()){
                    mp1[pattern[j]]=word[j];
                }
                else{
                    if(it1->second!=word[j]){
                        flag=0;
                        break;
                    }
                }
                if(it2==mp2.end()){
                    mp2[word[j]]=pattern[j];
                }
                else{
                    if(it2->second!=pattern[j]){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1){
                ans.push_back(word);
            }
        }
        return ans;
    }
};