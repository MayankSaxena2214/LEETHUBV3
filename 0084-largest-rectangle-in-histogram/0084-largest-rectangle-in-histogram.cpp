class Solution {
public:
    void nextSmaller(auto&arr,auto&next,auto&n){
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            next[i]=st.top();
            st.push(i);
        }

    }
    void prevSmaller(auto&arr,auto&prev,auto&n){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }
            prev[i]=st.top();
            st.push(i);
        }
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n),prev(n);
        prevSmaller(heights,prev,n);
        nextSmaller(heights,next,n);

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