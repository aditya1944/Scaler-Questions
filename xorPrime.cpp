#include<iostream>
#include<math.h>
#include<vector>
int solve(std::vector<int> &arr){
    int returnValue = 0;
    for(int index = 0;index<arr.size();++index){
        int currVal = arr[index];
        //find prime factors
        int xorValue = 0;
        int noOfPrime = 0;
        for(int prime = 2; prime<currVal;++prime){
            if(currVal%prime==0){
                ++noOfPrime;
                //std::cout<<prime<<" ";
                xorValue = xorValue^prime;
                while(currVal%prime==0){
                    currVal = currVal/prime;
                }
            }
        }
        if(currVal!=1){
            xorValue = xorValue|currVal;
            ++noOfPrime;
        }
        xorValue = xorValue * pow(2, noOfPrime-1);
        //std::cout<<xorValue<<" ";
        returnValue+=xorValue;
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    int output = solve(arr);
    std::cout<<output<<std::endl;
    return 0;
}