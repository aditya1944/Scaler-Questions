#include<iostream>
#include<vector>

int solve(int N){
    //if n is very large
    std::vector<int> dp(N+1);
    dp[0] = 0;
    dp[1] = 1;
    int sum = 1;
    for(int index = 2;index<=N;++index){
        if(index%2==0){
            dp[index] = dp[index/2];
        }
        else{
            dp[index] = dp[index-1] + 1;
        }
        sum+=dp[index];
        //std::cout<<dp[index]<<" ";
    }
    return sum;
}
int main(){
    std::cout<<solve(16)<<std::endl;
    return 0;
}