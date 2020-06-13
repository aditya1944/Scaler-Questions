#include<iostream>
#include<vector>
int solve(const std::string &str){
    std::vector<int> dp(str.size());
    dp[0] = 1;
    int maxLength = 1;
    for(int index = 1;index<str.size();++index){
        int j = index-1,currLength = 0;
        while(j>=0){
            if(str[j]<str[index]){
                currLength = std::max(currLength,dp[j] + 1);
            }
           --j;
        }
        dp[index] = currLength;
        maxLength = std::max(currLength,maxLength);
    }
    return maxLength;
}
int main(){
    std::string str = "hello";
    int output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}