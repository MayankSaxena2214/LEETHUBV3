class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())return "";
        int starti=0;
        int i=0,j=0;
        unordered_map<char,int>mp;
        for(auto ch:t){
            mp[ch]++;
        }
        int required=t.length();
        int minwindow=INT_MAX;
        int n=s.length();
        //if mp[ch]>0 then it means we want the character
        while(j<n){
            char ch=s[j];
            if(mp[ch]>0){
                required--;
            }
            mp[ch]--;
            
            while(required==0){
                    int currwindowsize=j-i+1;
                    if(currwindowsize<minwindow){
                        starti=i;
                        minwindow=currwindowsize;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        required++;
                    }
                    i++;
                }
            

            j++;
        }
        return minwindow==INT_MAX ? "": s.substr(starti,minwindow);
    }
};