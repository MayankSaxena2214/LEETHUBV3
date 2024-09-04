class Solution {
public:
    void solve(vector<int>&arr,int n,int index,int &count){
        if(index>=n){
            count++;
            return;
        }

        for(int i=index;i<n;i++){
            swap(arr[i],arr[index]);
            if((arr[i]%(i+1)==0) || ((i+1)%arr[i]==0)){
                solve(arr,n,index+1,count);
            }
            swap(arr[i],arr[index]);
        }
    }
    int countArrangement(int n) {
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int count=0;
        solve(arr,n,0,count);
        return count;
    }
};