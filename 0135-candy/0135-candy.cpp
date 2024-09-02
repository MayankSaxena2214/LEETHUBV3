class Solution {
public:
    int candy(vector<int>& candyType) {
        int n=candyType.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        for(int i=1;i<n;i++){
            if(candyType[i]>candyType[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(candyType[i]>candyType[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            prefix[i]=max(prefix[i],suffix[i]);
            sum+=prefix[i];
        }
        return sum;
    }
};