class Solution {
public:
    vector<int> buildArray(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            long long x=arr[i];
            long long y=arr[x];
            arr[i]=x+(y%n)*n;
        }
        for(int i=0;i<n;i++){
            arr[i]=arr[i]/n;
        }
        return arr;
    }
};