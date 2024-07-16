class Solution {
public:
    class Node{
    public :
    int data,i,j;
    Node(int d,int row,int col){
        data=d;
        i=row;
        j=col;
    }
};
class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data>b->data;
    }
};
    vector<int> smallestRange(vector<vector<int>>& nums) {
         int mini=INT_MAX,maxi=INT_MIN;
    priority_queue<Node*,vector<Node*>,compare>pq;
    for(int i=0;i<nums.size();i++){
        mini=min(mini,nums[i][0]);
        maxi=max(maxi,nums[i][0]);
        pq.push(new Node(nums[i][0],i,0));
    }
    int start=mini,end=maxi;
    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        mini=temp->data;
        if(end-start>maxi-mini){
            end=maxi;
            start=mini;
        }
        if(temp->j+1<nums[temp->i].size()){
            //we can push
            maxi=max(maxi,nums[temp->i][temp->j+1]);
            pq.push(new Node(nums[temp->i][temp->j+1],temp->i,temp->j+1));
        }
        else{
            break;
        }
    }
    return {start,end};
    }
};