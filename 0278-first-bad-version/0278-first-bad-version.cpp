// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1;
        int e=n;
        int ans=0;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(isBadVersion(mid)){
                ans=mid;
                e=mid-1;
                
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};