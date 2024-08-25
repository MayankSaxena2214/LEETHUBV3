class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<int>val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        for(int i=0;i<13;i++){
            if(num==0)break;
            if(num>=val[i]){
                int times=num/val[i];
                int freq=times;
                string temp=sym[i];
                while(times){
                    result+=temp;
                    times--;
                }
                num=num-freq*val[i];
            }
            
        }
        return result;
    }
};