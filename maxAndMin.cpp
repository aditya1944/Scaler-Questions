#include<iostream>
#include<vector>
#include<algorithm>
#define mod 1000000007
std::vector<int> solve(std::vector<int> &vec){
    std::vector<int> returnValue(2);
    std::sort(vec.begin(),vec.end());
    //max
    int half = vec.size()/2;
    long long maxMagicNum = 0;
    long long minMagicNum = 0;
    for(int index = 0;index<vec.size();index+=2){
        minMagicNum = (minMagicNum%mod + ((long long)vec[index+1]-(long long)vec[index]+mod)%mod)%mod;
    }
    for(int index = 0;index<vec.size();++index){
        if(index<half){
            maxMagicNum = (maxMagicNum - (long long)vec[index] + mod)%mod;
        }
        else{
            maxMagicNum = (maxMagicNum + (long long)vec[index])%mod;
        }
    }
    returnValue[0] = (int)maxMagicNum;
    returnValue[1] = (int)minMagicNum;
    return returnValue;
}   
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(vec);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}