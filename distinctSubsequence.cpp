#include<iostream>
#include<vector>
int solve(const std::string &A,const std::string &B){
    //find ways to convert A into B
    if(A.size()<B.size()){
        return 0;
    }
    const int rows = A.size()+1,cols = B.size()+1;
    std::vector<std::vector<int> > dp(A.size()+1,std::vector<int>(B.size()+1,0));
    dp[0][0]=1;
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        dp[rowIndex][0] = 1; 
    }
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex = 1;colIndex<cols;++colIndex){
            int temp;
            if(A[rowIndex-1]!=B[colIndex-1]){
                temp = dp[rowIndex-1][colIndex];
            }
            else{
                //the characters are equal
                //two possiblities
                temp = dp[rowIndex-1][colIndex-1] + dp[rowIndex-1][colIndex];
            }
            dp[rowIndex][colIndex] = temp;
        }
    }
    for(int rowIndex=0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            std::cout<<dp[rowIndex][colIndex]<<" ";
        }
        std::cout<<std::endl;
    }
    return dp[rows-1][cols-1];
}
int main(){
    std::string A,B;
    std::cin>>A>>B;
    int output = solve(A,B);
    std::cout<<output<<std::endl;
    return 0;
}