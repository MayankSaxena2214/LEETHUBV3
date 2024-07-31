class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            map<char,char>mp1;
            map<char,char>mp2;
            bool flag=1;
            for(int j=0;j<words[i].length();j++){
                auto it1=mp1.find(pattern[j]);
                auto it2=mp2.find(words[i][j]);
                if(it1==mp1.end()){
                    mp1[pattern[j]]=words[i][j];
                }
                else{
                    if(mp1[pattern[j]]!=words[i][j]){
                        flag=0;
                        break;
                    }
                }
                if(it2==mp2.end()){
                    mp2[words[i][j]]=pattern[j];
                }
                else{
                    if(mp2[words[i][j]]!=pattern[j]){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};