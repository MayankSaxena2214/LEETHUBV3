class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>maxiRight(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=temperatures[i];
            while(st.top()!=-1 && temperatures[st.top()]<=curr){
                st.pop();
            }
            maxiRight[i]=st.top();
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<maxiRight[i]<<" ";
        // }
        for(int i=0;i<n;i++){
            if(maxiRight[i]!=-1)
            maxiRight[i]=maxiRight[i]-i;
            else maxiRight[i]=0;
        }
        return maxiRight;
    }
};