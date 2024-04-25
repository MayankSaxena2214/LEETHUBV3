class Solution {
public:
    bool check(vector<int>&count1,vector<int>&count2){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        for(auto ch:s1){
            count1[ch-'a']++;
        }
        vector<int>count2(26,0);
        int window=s1.length();
        int i=0;
        while(i<window && i<s2.length()){
            count2[s2[i]-'a']++;
            i++;
        }
        
        if(check(count1,count2)){
            return true;
        }
        while(i<s2.length()){
            //remove the old character
            char old=s2[i-window];
            count2[old-'a']--;
            char naya=s2[i];
            count2[naya-'a']++;
            if(check(count1,count2)){
                return true;
            }
            i++;
        }
        return false;

    }
};