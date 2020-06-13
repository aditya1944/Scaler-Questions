#include<iostream>
#include<vector>
#include<unordered_set>
void helper(std::vector<int> &vec,int K, int lowPtr, int highPtr, int &returnValue){
    if(lowPtr<highPtr){
        //3 conditions
        int currSum = vec[lowPtr]+vec[highPtr];
        if(currSum==K){
            ++returnValue;
            //helper(vec,K,lowPtr+1,highPtr,returnValue);
            helper(vec,K,lowPtr,highPtr-1,returnValue);
        }
        else if(currSum<K){
            helper(vec,K,lowPtr+1,highPtr,returnValue);
        }
        else{
            helper(vec,K,lowPtr,highPtr-1,returnValue);
        }
    }
}
int solve(std::vector<int> &vec, int K){
    int lowPtr = 0,highPtr=vec.size()-1;
    int returnValue = 0;
    //std::unordered_set< > dp;
    helper(vec,K,lowPtr, highPtr,returnValue);
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
    std::cout<<output<<std::endl;
    return 0;
}