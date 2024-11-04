class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int idx1=(m+n)/2;
        int idx2=idx1-1;
        int i=0,j=0;
        int k=0; //index of virtually merged array
        int element1,element2;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                if(k==idx1){
                    element1=nums1[i];
                }
                if(k==idx2){
                    element2=nums1[i];
                }
                i++;
                k++;
            }
            else{
                if(k==idx1){
                    element1=nums2[j];
                }
                if(k==idx2){
                    element2=nums2[j];
                }
                j++;
                k++;
            }
        }
        while(i<n){
            if(k==idx1){
                    element1=nums1[i];
                }
                if(k==idx2){
                    element2=nums1[i];
                }
                i++;
        }
        while(j<m){
            if(k==idx1){
                    element1=nums2[j];
                }
                if(k==idx2){
                    element2=nums2[j];
                }
                j++;
                k++;
        }
        if((n+m)&1){
            return element1;
        }
        else{
            return (element1+element2)/2.0;
        }

        // if(n>m){
        //     return findMedianSortedArrays(nums2,nums1);
        // }
        // int l=0;
        // int r=n;
        // while(l<=r){
        //     int mid=(l+(r-l)/2);
        //     int Px=mid;
        //     int Py=(m+n+1)/2-Px;
        //     int x1=(Px==0)?INT_MIN:nums1[Px-1];
        //     int x2=(Px==n)?INT_MAX:nums1[Px];
        //     int y1=(Py==0)?INT_MIN:nums2[Py-1];
        //     int y2=(Py==m)?INT_MAX:nums2[Py];
        //     if(x1<=y2 && y1<=x2){
        //         if((n+m)&1){
        //             //odd
        //             return max(x1,y1);
        //         }
        //         else{
        //             int a=max(x1,y1);
        //             int b=min(x2,y2);
        //             return (a+b)/2.0;
        //         }
        //     }
        //     else if(x1>y2){
        //         r=mid-1;
        //     }
        //     else{
        //         l=mid+1;
        //     }
        // }
        // return -1;
    }
};