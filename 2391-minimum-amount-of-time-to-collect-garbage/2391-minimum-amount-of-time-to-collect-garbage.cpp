class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        int i=0;
        int n=garbage.size();
        int gindex=0,mindex=0,pindex=0;
        for(auto str:garbage){
            if(str.find('G')!=string::npos)gindex=i;
            if(str.find('M')!=string::npos)mindex=i;
            if(str.find('P')!=string::npos)pindex=i;
            ans+=str.length();
            i++;
        }
        for(int j=0;j<travel.size();j++){
            if(gindex>j)ans+=travel[j];
            if(mindex>j)ans+=travel[j];
            if(pindex>j)ans+=travel[j];
        }
        return ans;
    }
};