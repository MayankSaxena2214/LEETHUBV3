class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        if(s2.length()<s1.length())return false;
        for(int i=0;i<s1.length();i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;

        }
        if(count1==count2)return true;
        int n=s1.length();
        int i=n;
        
        while(i<s2.length()){
            //new char
            count2[s2[i]-'a']++;
            //remove old char
            count2[s2[i-n]-'a']--;
            if(count1==count2)return true;
            i++;
        }
        return false;
    }
};