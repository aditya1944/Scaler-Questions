#include<iostream>
#include<math.h>
#include<climits>
//#include<string>
int isPossible(unsigned long long N, unsigned long long base, int maxDigits){
    int returnValue = 0;
    //0 for underflow , 1 for equals, 2 for overflow
    int digits = 0;
    unsigned long long currSum = 0,factor = 1;
    //++maxDigits;
    while(digits<=maxDigits){
        currSum += factor;
        if(currSum == N){
            returnValue =  1;
            break;
        }
        else if(currSum>N){
            returnValue = 2;
            break;
        }
        ++digits;
        factor*=base;
    }
    return returnValue;
}
std::string solve(std::string str){
    int returnValue = INT_MAX;
    unsigned long long N = strtoull(str.c_str(),nullptr,10);
    for(int digit=1;digit<=64;++digit){
        unsigned long long low = 2, high = N-1;
        while(low<=high){
            unsigned long long mid = low + (high-low)/2;
            int flag = isPossible(N,mid,digit);
            //std::cout<<"mid: "<<mid<<"flag: "<<flag<<std::endl;
            if(flag==0){
                low = mid+1;
            }
            else if(flag==1){
                if(mid<returnValue)
                    returnValue = mid;
                high = mid-1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return std::to_string(returnValue);
}
int main(){
    std::string str;
    std::cin>>str;
    std::string output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}