class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1)return 0;
        vector<int>prime(n,true);
        prime[0]=false;
        prime[1]=false;
        int count=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
                //mark false for multiples
                for(int j=2*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }        
        return count;
    }
};