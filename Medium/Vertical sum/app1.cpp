class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        // add code here.
        vector<int>v;
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            Node*top=front.first;
            int hd=front.second.first;
            int lvl=front.second.second;
            nodes[hd][lvl].push_back(top->data);
            if(top->left){
                q.push({top->left,{hd-1,lvl+1}});
            }
            if(top->right){
                q.push({top->right,{hd+1,lvl+1}});
            }
        }
        for(auto i:nodes){
            int sum=0;
            for(auto j:i.second){
                
                for(auto k:j.second){
                    sum+=k;
                }
                
            }
            v.push_back(sum);
        }
        return v;
    }
};
