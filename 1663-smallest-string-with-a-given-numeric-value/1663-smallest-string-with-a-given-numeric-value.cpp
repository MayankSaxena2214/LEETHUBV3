class Solution {
public:
    string getSmallestString(int n, int k) {
        if(k<n)return "";
        vector<int>v(n,1);
        k=k-n;
        int i=n-1;
        string ans;
        while(k>0){
            if(k>=25){
                v[i]=v[i]+25;
                i--;
                k=k-25;
            }
            else{
                v[i]=v[i]+k;
                k=k-k;
                i--;
            }
        }
        for(auto val:v){
            char ch=val-1+'a';
            ans+=ch;
        }
        return ans;

    }
};