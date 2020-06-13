#include<iostream>
#include<vector>
#include<climits>
int solve(const std::vector<int> &prices, int K){
    const int rows = K+1,cols = prices.size();
    std::vector<std::vector<int> >dp(rows, std::vector<int>(cols));
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex = 1;colIndex<cols;++colIndex){
            dp[rowIndex][colIndex] = dp[rowIndex-1][colIndex];//do not transact
            int currDayPrice = prices[colIndex];
            int profit = INT_MIN;
            int prevMax = 0,currMax;
            for(int prevDay = colIndex-1;prevDay>=0;--prevDay){
                profit = std::max(profit,prices[colIndex] + dp[rowIndex-1][prevDay] - prices[prevDay]);
            }
            dp[rowIndex][colIndex] = std::max(dp[rowIndex][colIndex], profit);
        }
    }
    return dp[rows-1][cols-1];
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> prices(N);
    for(int index = 0;index<N;++index){
        std::cin>>prices[index];
    }
    std::cin>>K;
    int output = solve(prices, K);
    std::cout<<output<<std::endl;
    return 0;
}