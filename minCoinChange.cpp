#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
int solve(std::vector<int> &coins, int amount){
    std::vector<int> dp(amount+1,INT_MAX);
    dp[0] = 0;
    for(int num = 1;num<=amount;++num){
        for(int coin:coins){
            if(num==coin){
                dp[num]=1;
            }
            else if(coin<num){
                if(dp[num-coin]!=INT_MAX){
                    dp[num] = std::min(dp[num-coin]+1,dp[num]);
                }
            }
        }
        //std::cout<<dp[num]<<" ";
    }
    if(dp[amount]==INT_MAX){
        return -1;
    }
    return dp[amount];
}
int main(){
    int N,amount;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>amount;
    int output = solve(vec,amount);
    std::cout<<output<<std::endl;
    return 0;
}