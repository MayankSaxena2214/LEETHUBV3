//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void prevSmaller(int*arr,vector<int>&ans,int n){
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
    }
    void nextSmaller(int*arr,vector<int>&ans,int n){
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
    }
    int largestRectangle(int*heights,int n) {
        // int n=heights.size();
        vector<int>prev(n);
        vector<int>next(n);
        prevSmaller(heights,prev,n);
        nextSmaller(heights,next,n);

        int area=-1;
        for(int i=0;i<n;i++){
            int b=heights[i];
            if(next[i]==-1){
                next[i]=n;

            }
            int l=next[i]-prev[i]-1;
            area=max(area,l*b);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area=largestRectangle(M[0],m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1){
                    M[i][j]=M[i-1][j]+M[i][j];
                }
                else{
                    M[i][j]=0;
                }
                
            }
            area=max(area,largestRectangle(M[i],m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends