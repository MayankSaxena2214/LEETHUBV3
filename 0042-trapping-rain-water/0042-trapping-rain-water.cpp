class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                left[i]=arr[i];
            }
            else{
                left[i]=max(left[i-1],arr[i]);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                right[i]=arr[i];
            }
            else{
                right[i]=max(right[i+1],arr[i]);
            }
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans+=min(left[i],right[i])-arr[i];
        }
        return ans;
    }
};