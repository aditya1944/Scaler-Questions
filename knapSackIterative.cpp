#include<iostream>
#include<vector>
#include<climits>
int solve(const std::vector<int> &values, const std::vector<int> &weights, int maxWeight){
    if(values.size()==0 || maxWeight==0){
        return 0;
    }
    const int cols = maxWeight+1;
    const int rows = values.size()+1;
    std::vector<std::vector<int> >dp(rows, std::vector<int>(cols, 0));//stores the val
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex = 1;colIndex<cols;++colIndex){
            //fill dp[i][j]
            dp[rowIndex][colIndex] = INT_MIN;
            if(weights[rowIndex-1]<=colIndex){
                dp[rowIndex][colIndex] = dp[rowIndex-1][colIndex - weights[rowIndex-1]];
            }
            dp[rowIndex][colIndex] = std::max(dp[rowIndex][colIndex],dp[rowIndex-1][colIndex]);
        }
    }
    return dp[rows-1][cols-1];
}
int main(){
    return 0;
}