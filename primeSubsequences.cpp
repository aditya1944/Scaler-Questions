#include<iostream>
#include<vector>
#include<math.h>
#define mod 1000000007
class Number{
    private:
        std::vector<bool> primeDatabase;
    public:
        Number(){
            primeDatabase.reserve(1000001);
            for(int index = 0;index<1000001;++index){
                primeDatabase[index] = false;
            }
            initiliase();
        }
        void initiliase(){
            int maxNumber = 1000001;
            primeDatabase[0] = primeDatabase[1] = false;
            //primeDatabase[2] = true;
            int sqrtNum = sqrt(maxNumber);
            for(int num = 2;num<=sqrtNum;++num){
                if(primeDatabase[num]==false){
                    for(int num1 = num*num;num1<=maxNumber;num1 +=num){
                        primeDatabase[num] = true;
                    }
                }
            }
        }
        bool isPrime(int number){
            return primeDatabase[number];
        }
};
int fastMul(int pow){
    if(pow==0){
        return 1;
    }
    if(pow==1){
        return 2;
    }
    int returnValue;
    if(pow%2==0){
        int small = fastMul(pow/2);
        returnValue = ((long long)small%mod * (long long)small%mod)%mod;
        
    }
    else if(pow%2!=0){
        int small = fastMul(pow-1);
        returnValue = (2 * (long long)fastMul(pow-1))%mod;
    }
    return returnValue;
}
int solve(const std::vector<int> &A){
    Number *prime = new Number();
    //calculate number of prime Numbers
    int count = 0;
    for(int index = 0;index<A.size();++index){
        if(!(prime->isPrime(A[index]))){
            ++count;
        }
    }
    //calculate 2^count;
    int returnValue  = fastMul(count);
    return returnValue;
}
int main(){
    return 0;
}