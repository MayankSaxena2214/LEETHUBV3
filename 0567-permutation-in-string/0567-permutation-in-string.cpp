class Solution {
public:
    bool checkEqual(auto&count1,auto&count2){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        for(int i=0;i<s1.length();i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        if(checkEqual(count1,count2))return true;
        int i=s1.length();
        while(i<s2.length()){
            //removal logic
            int oldIndex=i-s1.length();
            count2[s2[oldIndex]-'a']--;
            //addition  logic
            count2[s2[i]-'a']++;
            if(checkEqual(count1,count2)){
                return true;
            }
            i++;
        }
        return false;
    }
};