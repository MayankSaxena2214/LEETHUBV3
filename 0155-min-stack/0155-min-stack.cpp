class MinStack {
public:
stack<long long>st;
        long long mini=INT_MAX;
    MinStack() {
                
    }
    
    void push(long long val) {
        if(st.empty()){
            st.push(val);
            mini=val;
            return;
        }
        if(val<mini){
            long long num=2*val-mini;
            st.push(num);
            mini=val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long curr=st.top();
        st.pop();
        if(curr<mini){
            long long prevmini=2*mini-curr;
            mini=prevmini;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        if(st.top()<mini){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        if(st.empty())return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */