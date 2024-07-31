class Solution {
public:
    string getSmallestString(int n, int k) {
        if(n>k){
            return "";
        }
        vector<int>v(n,1);
        k=k-n;
        int i=n-1;
        while(k){
            if(k>25){
                v[i]=v[i]+25;
                k=k-25;
                i--;
            }
            else{
                v[i]=v[i]+k;
                k=k-k;
                i--;
            }
        }
        string ans;
        for(auto val:v){
            ans.push_back(val-1+'a');
        }
        return ans;
    }
};