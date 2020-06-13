#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
int helper(const std::vector<int> &vec,int halfSum,int currIndex,int currSum){
    
}
int solve(const std::vector<int> &vec){
    //flip current number or not
    //reach S/2;
    int totalSum = 0;
    for(int index = 0;index<vec.size();++index){
        totalSum += vec[index];
    }
    int noOfElements = helper(vec,totalSum/2,0,0);
    return noOfElements;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    int index = 0;
    while(index<N){
        std::cin>>vec[index++];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}