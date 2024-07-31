//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(int n, vector<string> dict, string pattern);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        string tt;
        cin >> tt;

        vector<string> res = findMatchedWords(n, s, tt);
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends


/* The function returns a  vector of strings
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(int n, vector<string> words, string pattern) {
    // Your code here
            vector<string>ans;
        for(int i=0;i<words.size();i++){
            map<char,char>mp1;
            map<char,char>mp2;
            bool flag=1;
            for(int j=0;j<words[i].length();j++){
                if(pattern.length()!=words[i].length()){
                    flag=0;
                    break;
                }
                auto it1=mp1.find(pattern[j]);
                auto it2=mp2.find(words[i][j]);
                if(it1==mp1.end()){
                    mp1[pattern[j]]=words[i][j];
                }
                else{
                    if(mp1[pattern[j]]!=words[i][j]){
                        flag=0;
                        break;
                    }
                }
                if(it2==mp2.end()){
                    mp2[words[i][j]]=pattern[j];
                }
                else{
                    if(mp2[words[i][j]]!=pattern[j]){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1){
                ans.push_back(words[i]);
            }
        }
        return ans;
    
}