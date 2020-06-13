#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
std::vector<int> findNewArr(const std::vector<int> &A, int leftIndex, int rightIndex){
    std::vector<int> newArr(A.size()-2);
    int newArrIndex = 0;
    for(int index = 0;index<A.size();++index){
        if(index==leftIndex || index==rightIndex){
            continue;
        }
        newArr[newArrIndex++] = A[index];
    }
    return newArr;
}
int findSum(const std::vector<int> &vec){
    int sum = 0;
    for(int index = 0;index<vec.size()-1;index+=2){
        sum+=(abs(vec[index] - vec[index+1]));
    }
    return sum;
}
int solve(std::vector<int> &A){
    int minSum = INT_MAX;
    //take two element and remove it and find sum;
    for(int leftIndex = 0;leftIndex<A.size();++leftIndex){
        for(int rightIndex = leftIndex+1;rightIndex<A.size();++rightIndex){
            std::vector<int> newArr = findNewArr(A,leftIndex,rightIndex);
            int currSum = findSum(newArr);
            minSum = std::min(minSum,currSum);
        }
    }
    return minSum;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}