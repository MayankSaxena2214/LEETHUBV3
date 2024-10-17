class Solution {
public:
    void prevSmaller(auto&arr,auto&ans,auto&n){
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
    void nextSmaller(auto&arr,auto&ans,auto&n){
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
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
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
};