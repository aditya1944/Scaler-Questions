#include<iostream>
#include<vector>
#include<climits>
int helper(int maxWeight, const std::vector<int> &values, const std::vector<int> &weights, int currIndex){
    if(currIndex>=values.size() || maxWeight<0){
        return 0;
    }
    
    //three ways;
    //take current item => 2 ways;
    //do not take current item;
    int val1 =0,val2 = 0;
    if(maxWeight>=weights[currIndex]){
        val1 = helper(maxWeight - weights[currIndex],values,weights,currIndex+1) + values[currIndex];
        val2 = helper(maxWeight - weights[currIndex],values,weights,currIndex) + values[currIndex];
    }
    int val3 = helper(maxWeight,values,weights,currIndex+1);
    int maxVal = std::max(val1,std::max(val2,val3));
    return maxVal;
}
int solve(int maxWeight, std::vector<int> &values, std::vector<int> &weights){
    
    int maxVal = helper(maxWeight,values,weights,0);
    return maxVal;
}