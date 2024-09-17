class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int s=0,e=n-1;
        int ans=INT_MIN;
        while(s<e){
            int sh=height[s];
            int eh=height[e];
            int h=min(sh,eh);
            int l=e-s;
            ans=max(ans,l*h);
            if(sh>eh){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
    }
};