class Solution {
public:
    bool isPossible(auto&position,int m,int mid,int n){
        int count=1;
        int lastpos=position[0];
        for(int i=0;i<n;i++){
            if(position[i]-lastpos>=mid){
                count++;
                lastpos=position[i];
                if(count>=m)return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start=1;
        int n=position.size();
        int end=position[n-1]-position[0];
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(position,m,mid,n)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};