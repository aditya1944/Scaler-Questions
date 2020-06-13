#include<iostream>
#include<vector>
#define mod 1000000007
int solve(std::vector<int> &arr, int K){
    int lowPtr = 0,highPtr = arr.size()-1,returnValue = 0;
    while(lowPtr<=highPtr){
        long long currProd = (long long)arr[lowPtr] *(long long)arr[highPtr];
        if(currProd>=K){
            --highPtr;
        }
        else{
            returnValue = (returnValue + (2 * (highPtr-lowPtr) + 1)%mod)%mod;
            ++lowPtr;
        }
    }
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::cin>>K;
    int output = solve(arr,K);
    std::cout<<output<<std::endl;
    return 0;
}