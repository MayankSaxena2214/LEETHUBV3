class Solution {
public:
    bool checkEqual(vector<int>&v1,vector<int>&v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        int k=s1.length();
        if(s2.length()<s1.length())return false;
        for(int i=0;i<s1.length();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(checkEqual(v1,v2))return true;
        for(int i=k;i<s2.length();i++){
            int old=i-s1.length();
            v2[s2[old]-'a']--;
            //new 
            v2[s2[i]-'a']++;
            if(checkEqual(v1,v2))return true;

        }
        return false;
    }
};