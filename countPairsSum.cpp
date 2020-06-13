#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#define mod 1000000007
long long helper(int no){
    long long returnValue;
    if(no%2==0){
        int x = no/2;
        returnValue = (((long long)x * (long long)(no+1)) % mod);
        return returnValue;
    }
    else{
        int x = (no+1)/2;
        returnValue = (((long long)no * (long long)x) % mod);
        return returnValue;
    }
}
int solve(std::vector<int> &vec, int K){
    long long returnValue = 0, lowPtr = 0, highPtr = vec.size()-1;
    while(lowPtr<highPtr){
        long long currSum = (long long)vec[lowPtr] + (long long)vec[highPtr];
        if(currSum==(long long)K){
            if(vec[lowPtr]==vec[highPtr]){
                int no = highPtr-lowPtr;
                returnValue = (returnValue + helper(no))%mod;
                break;
            }
            else{
                int freqLowPtr = 1,lowPtrValue = vec[lowPtr];
                int freqHighPtr = 1,highPtrValue = vec[highPtr];
                ++lowPtr;
                while(lowPtrValue==vec[lowPtr]){
                    ++freqLowPtr;
                    ++lowPtr;
                }
                --highPtr;
                while(highPtrValue==vec[highPtr]){
                    ++freqHighPtr;
                    --highPtr;
                }
                long long combinations = ((long long)freqLowPtr * (long long)freqHighPtr)%mod;
                returnValue = (returnValue + combinations)%mod;
            }
        }
        else if(currSum<(long long)K){
            ++lowPtr;
        }
        else{
            --highPtr;
        }
    }
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>K;
    int output = solve(vec,K);
    //std::cout<<helper(7);
    std::cout<<output<<std::endl;
}