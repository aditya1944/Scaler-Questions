#include<vector>
#include<iostream>

int solve(const std::vector<int> &A){
    //take element of choice
    int maxVal = A[0],minVal = A[0],maxProduct = A[0];
    for(int index = 1;index<A.size();++index){
        if(A[index]<0){
            int temp = maxVal;
            maxVal = minVal;
            minVal = temp;
        }
        std::cout<<minVal<<" "<<maxVal<<std::endl; 
        maxVal = std::max(A[index],A[index]*maxVal);
        minVal = std::min(A[index],A[index]*minVal);
        maxProduct = std::max(maxVal,maxProduct);
    }
    return maxProduct;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int>input(N);
    for(int index= 0;index<N;++index){
        std::cin>>input[index];
    }
    int output = solve(input);
    std::cout<<output<<std::endl;
    return 0;
}