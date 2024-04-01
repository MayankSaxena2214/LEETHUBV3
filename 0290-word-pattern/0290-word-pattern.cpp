class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string buff;
        vector<string>temp;
        map<char,string>mp;
        map<string,char>mp2;
        
        while(ss>>buff){
            temp.push_back(buff);
        }
        if(temp.size()!=pattern.length())return false;
        for(int i=0;i<pattern.length();i++){
            if(mp.find(pattern[i])==mp.end()){
                mp[pattern[i]]=temp[i];
            }
            else{
                if(mp[pattern[i]]!=temp[i])return false;
            }
            //Two way mapping is needed for ex- pattern ="abba" && s ="dog dog dog dog"
            if(mp2.find(temp[i])==mp2.end())mp2[temp[i]]=pattern[i];
            else{
                if(mp2[temp[i]]!=pattern[i])return false;
            }
        }
        return true;
    }
};