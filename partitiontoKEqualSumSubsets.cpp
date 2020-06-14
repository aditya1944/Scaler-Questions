#include<iostream>
#include<vector>
#include<algorithm>
bool canPartitionKSubsets(std::vector<int>& nums, int k) {
    //can we partition the array in k parts such that sum of every parts are equal?
    //used backtracking approach
    int sum =  0 ;
    for(int index = 0;index<nums.size();++index){
        sum+=nums[index];
    }
    if(sum%k!=0){
        return false;
    }
    int currentPartition = k;
    int currentIndex = 0;
    //currSum denotes current sum of current partition
    int currSum = 0;
    int requiredSum = sum/k;
    std::vector<bool> visited(nums.size(),false);
    if(helper(currentPartition,currentIndex,currSum,requiredSum,visited,nums)){
        return true;
    }
    return false;
}
bool helper(int currentPartition, int currentIndex, int currSum, const int requiredSum,std::vector<bool> &visited,const std::vector<int> &nums){
    if(currentIndex==nums.size() || currSum>requiredSum){
        return false;
    }
    if(currentPartition==1){
        // k-1 partitions are made
        return true;
    }
    if(currSum==requiredSum){
        //1 partition completed 
        //go for next partition
        if(helper(currentPartition-1,0,0,requiredSum, visited,nums)){
            return true;
        }
        return false;
    }
    if(!visited[currentIndex]){
        //taking the element at currentIndex
        visited[currentIndex] = true;
        if(helper(currentPartition,currentIndex+1,currSum + nums[currentIndex], requiredSum,visited,nums)){
            return true;
        }
        //not taking the element at currentIndex
        visited[currentIndex] = false;
        if(helper(currentPartition,currentIndex+1,currSum,requiredSum,visited,nums)){
            return true;
        }
    }
    else{
        //just move forward
        if(helper(currentPartition,currentIndex+1,currSum,requiredSum,visited,nums)){
            return true;
        }
    }
    return false;
}