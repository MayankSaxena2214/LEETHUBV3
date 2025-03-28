class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n,true);
        if(n<=1)return 0;
        int count=0;
        prime[0]=false;
        prime[1]=false;

        for(int i=2;i<n;i++){
            if(prime[i]==true){
                count++;
                for(int j=i*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        return count;
    }
};