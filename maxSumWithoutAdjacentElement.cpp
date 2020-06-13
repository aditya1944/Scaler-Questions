#include<vector>
#include<iostream>
int adjacent(std::vector<std::vector<int> > &A) {
    //base cases
    if(A[0].size()==1){
        return std::max(A[0][0],A[0][1]);
    }
    std::vector<std::vector<int> > dp(2, std::vector<int>(A[0].size()+1,0));
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = A[0][0];
    dp[1][1] = A[1][0];
    for(int colIndex = 1;colIndex<A[0].size();++colIndex){
        for(int rowIndex = 0;rowIndex<2;++rowIndex){
            //take this element
            int maxAfterTakingThisElement;
            int maxAfterNotTakingThisElement;
            if(rowIndex==0){
                maxAfterTakingThisElement = std::max(A[0][colIndex] + dp[0][colIndex-1],A[0][colIndex] + dp[1][colIndex-1]);
                maxAfterNotTakingThisElement = std::max(dp[0][colIndex],dp[1][colIndex]);
            }
            else{
                maxAfterTakingThisElement = std::max(A[1][colIndex] + dp[0][colIndex-1],A[1][colIndex] + dp[1][colIndex-1]);
                maxAfterNotTakingThisElement = std::max(dp[1][colIndex],std::max(dp[0][colIndex-1],dp[0][colIndex+1]));
            }
            dp[rowIndex][colIndex+1] = std::max(maxAfterTakingThisElement,maxAfterNotTakingThisElement);
        }
    }
    /*for(int rowIndex = 0;rowIndex<2;++rowIndex){
        for(int colIndex = 0;colIndex<dp[0].size();++colIndex){
            std::cout<<dp[rowIndex][colIndex]<<" ";
        }
        std::cout<<std::endl;
    }*/
    int returnValue = dp[1][dp[0].size()-1];
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::vector<int> > dp(2, std::vector<int>(N,-1));
    for(int rowIndex = 0;rowIndex<2;++rowIndex){
        for(int colIndex = 0;colIndex<N;++colIndex){
            std::cin>>dp[rowIndex][colIndex];
        }
    }
    int output = adjacent(dp);
    std::cout<<output<<std::endl;
    return 0;
}