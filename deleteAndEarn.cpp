#include<unordered_map>
#include<vector>
int deleteAndEarn(std::vector<int>& nums) {
        std::unordered_map<size_t,size_t> hashMap;
        size_t maxNum = 0;
        for(size_t val:nums){
            ++(hashMap[val]);
            maxNum = std::max(maxNum,val);
        }
        std::vector<size_t> dp(maxNum,0);
        dp[1] = hashMap[1];
        for(size_t num=1;num<=maxNum;++num){
            dp[num] = std::max(dp[num-2] + hashMap[num]*num,dp[num-1]);    
        }
        return dp[maxNum];
}