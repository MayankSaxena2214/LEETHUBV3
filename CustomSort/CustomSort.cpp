#include <bits/stdc++.h> 
string specificOrder(string & x, string & y) {
    // Write your code here.
    string ans;
    vector<int>count(26,0);
    for(int i=0;i<x.length();i++){
        count[x[i]-'a']++;

    }
    for(auto ch:y){
        while(count[ch-'a']>0){
            ans.push_back(ch);
            count[ch-'a']--;
        }
    }
    for(int i=0;i<26;i++){
        while(count[i]>0){
            ans.push_back(i+'a');
            count[i]--;
        }
    }
    return ans;
}