class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0;
        int r=n;
        while(l<=r){
            int mid=(l+(r-l)/2);
            int Px=mid;
            int Py=(m+n+1)/2-Px;
            int x1=(Px==0)?INT_MIN:nums1[Px-1];
            int x2=(Px==n)?INT_MAX:nums1[Px];
            int y1=(Py==0)?INT_MIN:nums2[Py-1];
            int y2=(Py==m)?INT_MAX:nums2[Py];
            if(x1<=y2 && y1<=x2){
                if((n+m)&1){
                    //odd
                    return max(x1,y1);
                }
                else{
                    int a=max(x1,y1);
                    int b=min(x2,y2);
                    return (a+b)/2.0;
                }
            }
            else if(x1>y2){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};
