#include<iostream>
#include<vector>
void helper(const std::vector<int> &arr,int currSize,int currSum, int currIndex,const int &size, int &result){
    if(currSize>size || currIndex>arr.size() || currSum>1000){
        return;
    }
    if(currSize==size){
        ++result;
        return;
    }
    //take this currIndex
    helper(arr, currSize+1, currSum+arr[currIndex],currIndex+1,size, result);
    //do not take this currIndex
    helper(arr,currSize,currSum,currIndex+1,size,result);
}
int solve(std::vector<int> &arr,const int &size){
    int returnValue = 0;
    int currIndex = 0,currSum = 0, currSize=0;
    helper(arr,currSize,currIndex,currSum,size,returnValue);
    return returnValue;
}
int main(){
    int N,size;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>size;
    int output = solve(vec,size);
    std::cout<<output<<std::endl;
    return 0;
}