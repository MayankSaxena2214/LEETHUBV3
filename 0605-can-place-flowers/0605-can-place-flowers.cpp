class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        int n=arr.size();
    int place=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            int prev=0,next=0;
        if(i==0 || arr[i-1]==0){
            prev=1;
        }
        if(i==n-1 || arr[i+1]==0){
            next=1;
        }
        if(prev && next){
            place++;
            arr[i]=1;
        }
        }
    }
    if(place>=k)return true;
    return false;
    }
};