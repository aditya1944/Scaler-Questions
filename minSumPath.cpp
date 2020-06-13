#include<iostream>
#include<vector>
int minimumTotal(std::vector<std::vector<int> > &A){
    //use bottom up approach
    std::vector<std::vector<int> >dp(A.size(),std::vector<int>(A[0].size(),0));
    //initialise dp last row
    for(int colIndex = 0;colIndex<A[0].size();++colIndex){
        dp[A.size()-1][colIndex] = A[A.size()-1][colIndex];
    }
    for(int rowIndex = A.size()-2;rowIndex>=0;--rowIndex){
        for(int colIndex = 0;colIndex<=rowIndex;++colIndex){
            dp[rowIndex][colIndex] = std::min(dp[rowIndex+1][colIndex] + A[rowIndex][colIndex],
            A[rowIndex][colIndex]+dp[rowIndex+1][colIndex+1]);
        }
    }
    return dp[0][0];
}
//[2]
//[3,4]
//[6,5,7]
//[4,1,8,3]
int main(){

    return 0;
}