#include<iostream>
#include<vector>
int isMatch(const std::string &B, const std::string &A){
    const int rows = A.size()+1,cols = B.size()+1;
    //considering only A has wild card characters
    std::vector<std::vector<bool> > dp(rows,std::vector<bool>(cols,true));
    //base cases
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        if(A[rowIndex-1]=='*'){
            if(dp[rowIndex-1][0]==true){
                dp[rowIndex][0] = true;
            }
            else{
                dp[rowIndex][0] = false;
            }
        }
        else{
            dp[rowIndex][0] = false;
        }
    }
    for(int colIndex = 1;colIndex<cols;++colIndex){
        dp[0][colIndex] = false;
    }
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex=1;colIndex<cols;++colIndex){
            bool temp;
            if(A[rowIndex-1]=='*'){
                bool value = false;
                for(int j = colIndex;j>=0;--j){
                    value = value | dp[rowIndex-1][j];
                }
                temp = value;
            }
            else if(A[rowIndex-1]=='?'){
                temp = dp[rowIndex-1][colIndex-1];
            }
            else{
                if(A[rowIndex-1]==B[colIndex-1]){
                    if(dp[rowIndex-1][colIndex-1]==false){
                        temp = false;
                    }
                    else{
                        temp = true;
                    }
                }
                else{
                    temp = false;
                }
            }
            dp[rowIndex][colIndex] = temp;
        }
    }
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex=0;colIndex<cols;++colIndex){
            std::cout<<dp[rowIndex][colIndex]<<" ";
        }
        std::cout<<std::endl;
    }
    return dp[rows-1][cols-1];
}
int main(){
    std::string s1, s2;
    std::cin>>s1>>s2;
    int output = isMatch(s1,s2);
    std::cout<<output<<std::endl;
    return 0;
}