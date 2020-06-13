#include<vector>
long long fastMultiplication(int x, int y, int p){
    long long res = 1; 
    x = x % p;
    while (y > 0)  
    {
        if (y & 1)  
            res = (res*(long long)x) % (long long)p;
        y = y>>1;
        x = ((long long)x*(long long)x) % p;  
    }  
    return res; 
}
    void factorial(int &n, int &r, int &nMinusR, int p){
        std::vector<long long> fact(n+1);
        fact[0] = fact[1] = 1;
        for(int index = 2;index<=n;++index){
            fact[index] = (fact[index-1]*(long long)index)%p;
        }
        nMinusR = fact[n-r];
        n = fact[n];
        r = fact[r];
    }
    int solve(int n, int r, int p) {
        if(p==1){
            return 0;
        }
        if(r==n){
            return 1;
        }
        long long returnValue;
        int nMinusR;
        factorial(n,r,nMinusR,p);
        //nCr % p => use fermat theorem
        returnValue = (((long long)n * fastMultiplication(r,p-2, p))%p * fastMultiplication(nMinusR,p-2,p))%p;
        int x = (int)returnValue;
        return x;
    }