class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        int window=s1.length();
        int mlen=s2.length();
        if(mlen<window)return false;
        for(int i=0;i<window;i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;

        }
        if(count1==count2)return true;
        int i=window;
        while(i<mlen){
            //remove old
            count2[s2[i-window]-'a']--;
            //additon
            count2[s2[i]-'a']++;
            if(count1==count2)return true;
            i++;
        }
        return false;

    }
};