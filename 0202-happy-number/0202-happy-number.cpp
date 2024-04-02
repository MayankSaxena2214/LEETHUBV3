class Solution {
public:
    bool isHappy(int n) {
        string num=to_string(n);
        if(n==1)return true;
        while(num!="1"){
            int ans=0;
            for(auto ch:num){
                int val=ch-'0';
                ans+=val*val;
            }
            if(ans==1)return true;
            if(ans==7)return true;
            if(ans<=9)break;
            num=to_string(ans);
        }
        
        return false;
    }
};