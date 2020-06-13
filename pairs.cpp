#include<iostream>
#include<vector>
#define mod 1000000007
int solve(std::vector<int> &arr, int K){
    //make buckets
    long long returnValue = 0;
    std::vector<long> bucket(K,0);
    for(int index = 0;index<arr.size();++index){
        ++bucket[arr[index]%K];
    }
    returnValue+=((bucket[0]*(bucket[0]-1))/2);
    for(int remainder = 1;remainder<=K/2;++remainder){
        returnValue= (returnValue + (bucket[remainder]*bucket[K-remainder])%mod)%mod;
    }
    if(K%2==0){
        returnValue=(returnValue + ((bucket[K/2]*(bucket[K/2]-1))/2)%mod)%mod;
    }
    return (int)returnValue;
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