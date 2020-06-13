#include<iostream>
#include<vector>
bool solve(std::string &pattern,std::string &str){
    //put pattern in cols and string in rows
    const int cols = pattern.size(),rows = str.size();
    std::vector<std::vector<bool> > dp(rows, std::vector<bool>(cols,false));
    dp[0][0] = true;
    for(int colIndex = 1;colIndex<cols;++colIndex){
        if(pattern[colIndex]=='*'){
            dp[0][colIndex] = dp[0][colIndex];
        }
    }
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex = 1;colIndex<cols;++colIndex){
            if(str[rowIndex-1]==pattern[colIndex-1] || pattern[colIndex-1]=='.'){
                dp[rowIndex][colIndex] = dp[rowIndex-1][colIndex-1];
            }
            
        }
    }
    return dp[rows-1][cols-1];
}
int main(){
    std::string pattern,string;
    std::cin>>pattern>>string;
    std::cout<<solve(pattern,string)<<std::endl;
    return 0;
}