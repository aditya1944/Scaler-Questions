#include<iostream>
#include<vector>
#define mod 1000000007

int helper(int noOfDice, const int& noOfFace, int target, std::vector<std::vector<int> >&dp){
    //base cases
    if(noOfDice==0 && target==0){
        return 1;
    }
    if(noOfDice==0){
        //noOfways =0
        return 0;
    }
    if(dp[noOfDice][target]!=-1){
        return dp[noOfDice][target];
    }
    //possiblities
    int noOfWays = 0;
    for(int face = 1;face<=noOfFace;++face){
        if(target-face<0){
            break;
        }
        noOfWays+=helper(noOfDice-1, noOfFace,target-face,dp);
    }
    dp[noOfDice][target] = noOfWays;
    return noOfWays;
}
int solve(int noOfDice,int noOfFace, int target){
    //find no of ways with all the dice
    std::vector<std::vector<int> >dp(noOfDice+1,std::vector<int>(target+1,-1));
    int returnValue = helper(noOfDice, noOfFace, target,dp);
    return returnValue;
}