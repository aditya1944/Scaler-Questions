#include<iostream>
#include<vector>
#include<climits>
int minSubArrayLen(int s, std::vector<int>& nums){
    int returnValue = INT_MAX;
    int sum = 0,left = 0;
    for(int right = 0;right<nums.size();++right){
        sum+=nums[right];
        while(sum>=s){
            returnValue = std::min(returnValue, right - left+1);
            sum-=nums[left];
            ++left;
        }
    }
    if(sum==INT_MAX){
        return 0;
    }
    return returnValue;
}
    
int main(){
    std::vector<int> vec = {2,3,1,2,4,3};
    std::cout<<minSubArrayLen(7,vec);
    return 0;
}