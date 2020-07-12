#include<iostream>
#include<vector>
#include<climits>
int maxCoins(std::vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    if(nums.size()==1){
        return nums[0];
    }
    const int size = nums.size();
    std::vector<std::vector<int> >dp(size,std::vector<int>(size,0));
    for(int length = 1;length<=size;++length){
        for(int start = 0;start<=size-length;++start){
            int end = start + length -1;
            //we have to fill dp[start][end]
            dp[start][end] = INT_MIN;
            int windowLeftBoundary, windowRightBoundary;
            windowLeftBoundary = (start-1<0)?1:nums[start-1];
            windowRightBoundary = (end+1>=size)?1:nums[end+1];
            for(int mid = start;mid<=end;++mid){    
                int leftWindowValue = (mid-1<start)?0:dp[start][mid-1];
                int rightWindowValue = (mid+1>end)?0:dp[mid+1][end];
                dp[start][end] = std::max(dp[start][end], windowLeftBoundary*nums[mid]*windowRightBoundary + leftWindowValue + rightWindowValue);
            }
        }
    }
    return dp[0][size-1];
}  