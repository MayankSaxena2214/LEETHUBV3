class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,n=height.size(),e=n-1;
        int ans=INT_MIN;
        while(s<e){
            int fh=height[s];
            int lh=height[e];
            int h=min(fh,lh);
            int l=e-s;
            ans=max(ans,l*h);
            if(fh>lh){
                e--;

            }
            else{
                s++;
            }
        }
        return ans;
    }
};