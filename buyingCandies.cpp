#include<iostream>
#include<vector>
int helper(const std::vector<int> &candies,const std::vector<int> &cost,const std::vector<int> &sweetness, int totalCost,int currIndex){
    if(currIndex>=candies.size() || totalCost<=0){
        return 0;
    }

    //two ways
    //1. buy current candies Packet
    int sweetVal1 = 0;
    if(cost[currIndex]>=candies[currIndex]){
        sweetVal1 = helper(candies,cost,sweetness,totalCost - cost[currIndex], currIndex+1) + sweetness[currIndex]*candies[currIndex];
    }
    int sweetVal2 = helper(candies,cost,sweetness,totalCost,currIndex+1);
    int maxSweet = std::max(sweetVal1,sweetVal2);
    return maxSweet;
}
int solve(const std::vector<int> &candies,const std::vector<int> &cost,const std::vector<int> &sweetness, int totalCost){
    //maximise total sweetness
    int maxSweetness = helper(candies,cost,sweetness,totalCost,0);
    return maxSweetness;
}
int main(){
    return 0;
}