#include<iostream>
#include<unordered_map>
#include<vector>
#define mod 1000000007
int helper(int currPos, int lastPos, int sum,std::vector<std::vector<int> >&dp){
    if(sum<0 || currPos>lastPos){
        return 0;
    }
    if(currPos==lastPos&& sum==0){
        return 1;
    }
    //currSum = 3   maxSum = 9
    //1-6
    //if currPos is 1
    //if(dp.find(currPos)!=dp.end())
    if(dp[currPos][sum]!=-1){
        return dp[currPos][sum];
    }
    int maxNum = sum;
    int minNum = (currPos==1)?1:0;
    int ways = 0;
    //std::cout<<sum<<" ";
    for(int k = minNum;k<=maxNum;++k){
        ways=(ways + helper(currPos+1,lastPos,sum - k,dp))%mod;
    }
    dp[currPos][sum] = ways;
    return ways;
}
int solve(int A,int B){
    int rows = A,cols = B;
    std::vector<std::vector<int> >dp(rows+1,std::vector<int>(cols+1,-1));
    int ways = helper(0,A,B,dp);
    return ways;
} 
int main(){
    int A,B;
    std::cin>>A>>B;
    int output = solve(A,B);
    std::cout<<output<<std::endl;
    return 0;
}