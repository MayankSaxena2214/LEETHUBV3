class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for(auto ch:stones){
            if(jewels.find(ch)!=string::npos){
                count++;
            }
        }
        return count;
    }
};