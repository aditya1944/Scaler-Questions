#include<iostream>
#include<vector>
int solve(const std::string &str1, const std::string &str2){
    const int rows = str1.size()+1,cols = str2.size()+1;
    std::vector<std::vector<int> > dp(rows,std::vector<int>(cols, 0));  
    //base cases initialised
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex = 1;colIndex<cols;++colIndex){
            int temp;
            if(str1[rowIndex-1]==str2[colIndex-1]){
                temp = 1 + dp[rowIndex-1][colIndex-1];
            }
            else{
                temp = std::max(dp[rowIndex][colIndex-1],dp[rowIndex-1][colIndex]);
            }
            dp[rowIndex][colIndex] = temp;
        }
    }
    return dp[rows-1][cols-1];
}
int main(){
    std::string str1,str2;
    std::cin>>str1>>str2;
    int output = solve(str1,str2);
    std::cout<<output<<std::endl;
    return 0;
}