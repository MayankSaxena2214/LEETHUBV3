class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        int index=0;
        int i=0,j=0,k=0;
        for(auto str:garbage){
            ans+=str.length();
            if(str.find('G')!=string::npos){
                i=index;
            }
            if(str.find('P')!=string::npos){
                j=index;
            }
            if(str.find('M')!=string::npos){
                k=index;
            }
            index++;
        }
        for(int itr=0;itr<travel.size();itr++){
            if(itr<i){
                ans+=travel[itr];
            }
            if(itr<j){
                ans+=travel[itr];
            }
            if(itr<k){
                ans+=travel[itr];
            }
        }
        return ans;
    }
};