class Solution {
public:
    vector<int>prevSmaller(auto&heights,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nextSmaller(auto&heights,int n){
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev(n),next(n);
        prev=prevSmaller(heights,n);
        next=nextSmaller(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            area=max(area,l*b);
        }
        return area;
    }
};