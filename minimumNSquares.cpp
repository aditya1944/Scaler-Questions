#include<math.h>
#include<climits>
#include<vector>
int countMinSquares(int A) {
    //range of squares will be from 1 to sqrt(A);
    std::vector<int> dp(A+1,INT_MAX);
    for(int index = 0;index<4;++index){
        dp[index] = index;
    }
    for(int index = 4;index<=A;++index){
        int sqrtNum = sqrt(index);
        for(int num = 1;num<=sqrtNum;++num){
            dp[index] = std::min(dp[index], 1 + dp[index - (num*num)]);
        }
    }
    return dp[A];
}