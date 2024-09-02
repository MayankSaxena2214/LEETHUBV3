class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<int>val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        for(int i=0;i<13;i++){
            if(num>=val[i]){
                int count=num/val[i];
                int freq=num/val[i];
                while(count!=0){
                    result+=sym[i];
                    count--;
                }
                num=num-freq*val[i];
            }
        }
        return result;
    }
};