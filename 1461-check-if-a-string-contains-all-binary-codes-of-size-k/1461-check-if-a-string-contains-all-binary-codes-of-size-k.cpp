class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)return false;
        map<string,bool>mp;
        for(int i=0;i<=s.length()-k;i++){
            mp[s.substr(i,k)]=true;
        }
        for(auto val:mp){
            cout<<val.first<<endl;
        }
        return mp.size()==pow(2,k);
    }
};