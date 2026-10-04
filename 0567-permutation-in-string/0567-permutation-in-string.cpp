class Solution {
public:
    bool checkEqual(int*arr1,int*arr2){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        //sliding window
        if(s1.length()>s2.length())return false;
        int count1[26]={0};
        int count2[26]={0};

        int n1=s1.length();
        int n2=s2.length();

        for(int i=0;i<n1;i++){
            int index1=s1[i]-'a';
            int index2=s2[i]-'a';
            count1[index1]++;
            count2[index2]++;
        }
        if(checkEqual(count1,count2))return true;
        int i=n1;
        while(i<n2){
            //new index
            int index=s2[i]-'a';
            count2[index]++;
            //old index remove
            int  oldIndex=s2[i-n1]-'a';
            count2[oldIndex]--;
            if(checkEqual(count1,count2))return true;
            i++;
        }
        return false;
    }
};