#include<iostream>
#include<vector>
#include<algorithm>
#define mod 1000000007
std::vector<int> solve(const std::string &str){
    //find common subsequences
    std::string reverseString = str;
    std::reverse(reverseString.begin(),reverseString.end());
    const int n = str.size()+1;
    std::vector<int> ans(n-1,1);
    std::vector<std::vector<int> >dp(str.size()+1, std::vector<int>(n,0));
    for(int rowIndex = 1;rowIndex<n;++rowIndex){
        for(int colIndex = 1;colIndex<n;++colIndex){
            dp[rowIndex][colIndex] = ((dp[rowIndex-1][colIndex] + dp[rowIndex][colIndex-1])%mod -dp[rowIndex-1][colIndex-1] + mod)%mod;
            if(str[rowIndex-1]==reverseString[colIndex-1]){
                dp[rowIndex][colIndex]= (dp[rowIndex][colIndex] + (1 + dp[rowIndex-1][colIndex-1])%mod)%mod;
            }
        }
    }
    /*for(int rowIndex = 0;rowIndex<n;++rowIndex){
        for(int colIndex = 0;colIndex<n;++colIndex){
            std::cout<<dp[rowIndex][colIndex]<<" ";
        }
        std::cout<<std::endl;
    }*/
    for(int index = 1;index<ans.size()-1;++index){
        ans[index] = (ans[index] + dp[index][str.size() - index-1])%mod;
    }
    return ans;
}
int main(){
    std::string A;
    std::cin>>A;
    std::vector<int> output = solve(A);
    for(int& x: output){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
}