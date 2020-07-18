#include<iostream>
#include<vector>
std::vector<int> print(int n){
    
    //n is row and col also
    std::vector<int> dp(n+1,0);
    if(n==1){
        dp[0] = 1;
        return dp;
    }
    if(n==2){
        dp[0] = dp[1] = 1;
        return dp;
    }
    dp[0] = dp[1] = 1;
    for(int rowIndex = 3;rowIndex<=n;++rowIndex){
        int a = 1;
        dp[0] = 1;
        for(int colIndex = 1;colIndex<rowIndex;++colIndex){
            int temp = dp[colIndex];
            dp[colIndex] = dp[colIndex] + a;
            a = temp;
        }
    }
    return dp;
}

int main(){
    std::vector<int> returnValue = print(7);
    for(int &val: returnValue){
        std::cout<<val<<" ";
    }
    return 0;
}