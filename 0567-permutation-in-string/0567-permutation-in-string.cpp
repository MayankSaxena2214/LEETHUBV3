class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        int n=s1.length(),m=s2.length();
        if(n>m)return false;
        for(int i=0;i<n;i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        if(count1==count2)return true;
        int i=n;
        while(i<m){
            //remove old char
            count2[s2[i-n]-'a']--;
            count2[s2[i]-'a']++;
            if(count2==count1)return true;
            i++;
        }
        return false;
    }
};