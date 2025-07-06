// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        //  code here
        vector<int>ans(arr.size());
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                ans[i]=arr[i+1];
            }
            else{
                ans[i]=-1;
            }
        }
        ans[arr.size()-1]=-1;
        arr=ans;
    }
};