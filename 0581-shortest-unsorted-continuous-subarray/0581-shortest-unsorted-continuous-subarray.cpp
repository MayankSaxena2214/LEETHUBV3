class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        if(arr.size()==1)return 0;
        int n=arr.size();
        int maxi=INT_MIN,mini=INT_MAX;
        bool flag=1;
        for(int i=0;i<n;i++){
            if(i==0){
                if(arr[i]>arr[i+1]){
                    flag=0;
                    maxi=max(maxi,arr[i]);
                    mini=min(mini,arr[i]);
                }
            }
            else if(i==n-1){
                if(arr[i]<arr[i-1]){
                    flag=0;
                    maxi=max(maxi,arr[i]);
                    mini=min(mini,arr[i]);
                }
            }
            else{
                if(arr[i]>arr[i+1] || arr[i]<arr[i-1]){
                    flag=0;
                    maxi=max(maxi,arr[i]);
                    mini=min(mini,arr[i]);
                }
            }
        }
        if(flag==1)return 0;
        int i,j;
        for(i=0;i<n && arr[i]<=mini;i++){
            
        }
        for(j=n-1;j>=0 && arr[j]>=maxi;j--){}
        return j-i+1;
    }
};