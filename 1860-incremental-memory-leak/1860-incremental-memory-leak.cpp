class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int t=1;
        while(true){
            if(memory1>=t || memory2>=t){
                if(memory1>=memory2){
                    memory1-=t;

                }
                else{
                    memory2-=t;
                }
                t++;
            }
            else{
                vector<int>ans;
                ans.push_back(t);
                ans.push_back(memory1);
                ans.push_back(memory2);
                return ans;
            }
        }
        return {};
    }
};