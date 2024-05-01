class MinStack {
public:
    stack<int>st;
    int mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                st.push(2*val-mini);
                mini=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        int val=st.top();
        st.pop();
        if(val<mini){
            int prevmini=2*mini-val;
            mini=prevmini;
            
        }
        else{
            
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        if(st.top()<mini){
            return mini;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
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