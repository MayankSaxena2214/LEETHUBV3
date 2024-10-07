class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        if(s2.length()<s1.length())return false;
        int k=s1.length();
        for(int i=0;i<k;i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        if(count1==count2)return true;
        int m=s2.length();
        int i=k;
        while(i<m){
            //removal
            count2[s2[i-k]-'a']--;
            count2[s2[i]-'a']++;
            if(count2==count1)return true;
            i++;
        }
        return false;
        
    }
};