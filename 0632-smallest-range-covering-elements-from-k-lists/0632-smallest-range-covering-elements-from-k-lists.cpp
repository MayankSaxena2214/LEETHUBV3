class Solution {
public:
    class Node{
        public:
            int data;
            int i;
            int j;
        public:
            Node(int data,int i,int j){
                this->data=data;
                this->i=i;
                this->j=j;
            }
    };
    class compare{
        public:
            bool operator()(Node*a,Node*b){
                return a->data>b->data;
            }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<Node*,vector<Node*>,compare>pq;

        int maxi=INT_MIN,mini=INT_MAX;

        for(int i=0;i<k;i++){
            int val=nums[i][0];
            maxi=max(maxi,val);
            mini=min(mini,val);
            pq.push(new Node(val,i,0));
        }
        int end=maxi;
        int start=mini;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int data=top->data;
            int row=top->i;
            int col=top->j;
            mini=data;
            if(maxi-mini<end-start){
                end=maxi;
                start=mini;
            }
            if(col+1<nums[row].size()){
                pq.push(new Node(nums[row][col+1],row,col+1));
                maxi=max(maxi,nums[row][col+1]);

            }
            else{
                break;
            }
        }
        return {start,end};

    }
};