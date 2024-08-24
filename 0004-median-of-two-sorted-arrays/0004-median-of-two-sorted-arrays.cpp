class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int l=0,r=n;
        while(l<=r){
            int Px=l+(r-l)/2;
            int Py=(m+n+1)/2 -Px;

            int x1=(Px==0)?INT_MIN:nums1[Px-1];
            int y1=(Py==0)?INT_MIN:nums2[Py-1];
            int x2=(Px==n)?INT_MAX:nums1[Px];
            int y2=(Py==m)?INT_MAX:nums2[Py];

            if(x1<=y2 && y1<=x2){
                if((n+m)%2==0){
                    return (max(x1,y1)+min(x2,y2))/2.0;
                }
                else{
                    return (max(x1,y1));
                }
            }
            else if(x1>y2){
                r=Px-1;
            }
            else{
                
                l=Px+1;
            }
        }
        return -1;
        // int n=nums1.size();
        // int m=nums2.size();
        // if(n>m)return findMedianSortedArrays(nums2,nums1);

        // int l=0;
        // int r=n;
        // while(l<=r){
        //     int Px=(l+(r-l)/2);
        //     int Py=(m+n+1)/2-Px;

        //     //left vaale element
        //     int x1=(Px==0)?INT_MIN:nums1[Px-1];
        //     int y1=(Py==0)?INT_MIN:nums2[Py-1];
        //     //right vaale
        //     int x2=(Px==n)?INT_MAX:nums1[Px];
        //     int y2=(Py==m)?INT_MAX:nums2[Py];

        //     if(x1<=y2 && y1<=x2){
        //         if((m+n)%2==0){
        //             return (max(x1,y1)+min(x2,y2))/2.0;
        //         }
        //         else{
        //             return max(x1,y1);
        //         }
        //     }
        //     if(x1>y2){
        //         r=Px-1;
        //     }
        //     else{
        //         l=Px+1;
        //     }
        // }
        // return -1;
        
    }
};