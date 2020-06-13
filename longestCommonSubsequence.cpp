#include<iostream>
#include<vector>
int longestCommonSubsequence(const std::string &text1,const std::string &text2) {
    const int rows = text1.size()+1;
    const int cols = text2.size()+1;
    std::vector<std::vector<int> > dp(rows,std::vector<int>(cols,0));
    //"abcd"
    //"bc"
    //f(i,j) = max(f(i-1,j),f(i,j-1)) => if(char[i]!=char[j])
    //f(i,j) = 1 + f(i-1,j-1);
    //base cases
    //"abcd"
    //""
    //0
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex = 1;colIndex<cols;++colIndex){
            int temp;
            if(text1[rowIndex-1]==text2[colIndex-1]){
                temp = 1 + dp[rowIndex-1][colIndex-1];
            }
            else{
                temp = std::max(dp[rowIndex-1][colIndex],dp[rowIndex][colIndex-1]);
            }
            temp = dp[rowIndex][colIndex];
        }
    }
    return dp[rows-1][cols-1];
}
int main(){
    std::string str = "";
    return 0;
}