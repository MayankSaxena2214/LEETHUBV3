class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int i=1;
        int n=arr.size();
        while(i<n-1){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                //mountain
                int j=i;
                while(j>0 && arr[j]>arr[j-1]){
                    j--;
                }
                while(i<n-1 && arr[i]>arr[i+1]){
                    i++;
                }
                ans=max(ans,i-j+1);
            }
            {
                i++;
            }
        }
        return ans;
    }
};