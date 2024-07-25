class Solution {
public:
    vector<int>previousSmaller(vector<int>&arr,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nextSmaller(vector<int>&arr,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangle(vector<int>&arr,int n){
        vector<int>prev(n);
        vector<int>next(n);
        prev=previousSmaller(arr,n);
        next=nextSmaller(arr,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=arr[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            area=max(area,l*b);
            
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    arr[i][j]=1;
                }
            }
        }
         int area=largestRectangle(arr[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    arr[i][j]=arr[i-1][j]+arr[i][j];
                }
                else{
                    arr[i][j]=0;
                }
            }
            area=max(largestRectangle(arr[i],m),area);
        }
        return area;
    }
};