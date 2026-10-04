class Solution {
public:
bool isPossible(vector<int>&stalls,int n,int k,int mid){
    int lastPos=stalls[0];
    int cowCount=1;
    for(int i=0;i<n;i++){
        if(stalls[i]-lastPos>=mid){
            cowCount++;
            lastPos=stalls[i];
            if(cowCount==k)return true;
        }

    }
    return false;

}
    int maxDistance(vector<int>& stalls, int k) {
        //    Write your code here.
    int n=stalls.size();
    int s=0;
    sort(stalls.begin(),stalls.end());
    int  e=stalls[n-1];
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(stalls,n,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    }
};