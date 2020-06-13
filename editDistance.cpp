#include<iostream>
#include<vector>
int solve(const std::string &A, const std::string &B){
    //using bottom up approach
    std::vector<std::vector<int> > dp(A.size()+1,std::vector<int>(B.size()+1,0));
    const int n = A.size()+1,m = B.size()+1;
    //first row base case
    for(int colIndex = 0;colIndex<m;++colIndex){
        dp[0][colIndex] = colIndex;
    }
    //first col Test Case
    for(int rowIndex = 0;rowIndex<n;++rowIndex){
        dp[rowIndex][0] = rowIndex;
    }
    for(int rowIndex = 1;rowIndex<n;++rowIndex){
        for(int colIndex = 1;colIndex<m;++colIndex){
            int temp;
            //std::cout<<rowIndex<<colIndex;
            if(A[rowIndex-1]==B[colIndex-1]){
                temp = dp[rowIndex-1][colIndex-1];
            }
            else{
                temp = 1 + std::min(dp[rowIndex-1][colIndex-1],std::min(dp[rowIndex-1][colIndex],dp[rowIndex][colIndex-1]));
            }
            dp[rowIndex][colIndex] = temp;
        }
    }
    return dp[n-1][m-1];
}
int main(){
    std::string str1,str2;
    std::cin>>str1>>str2;
    int output = solve(str1,str2);
    std::cout<<output<<std::endl;
    return 0;
}