#include<iostream>
#include<vector>
int checkRow(const std::vector<std::vector<char> >&matrix, int rowIndex, int colIndex){
    int returnValue = 0;
    --colIndex;
    while(colIndex>=0 && matrix[rowIndex][colIndex]=='1'){
        --colIndex;
        ++returnValue;
    }
    return returnValue;
}
int checkCol(const std::vector<std::vector<char> >&matrix, int rowIndex, int colIndex){
    int returnValue = 0;
    --rowIndex;
    while(rowIndex>=0 && matrix[rowIndex][colIndex]=='1'){
        --rowIndex;
        ++returnValue;
    }
    return returnValue;
}
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size()==0){
        return 0;
    }
    const int rows = matrix.size(),cols = matrix[0].size();
    std::vector<std::vector<int> > dp(rows,std::vector<int>(cols));
    int maxArea = 0;
    //fill first col
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        if(matrix[rowIndex][0]=='1'){
            maxArea = 1;
            dp[rowIndex][0] = 1;
        }
    }
    //fill first row
    for(int colIndex = 0;colIndex<cols;++colIndex){
        if(matrix[0][colIndex]=='1'){
            maxArea = 1;
            dp[0][colIndex] = 1;
        }
    }
    for(int rowIndex = 1;rowIndex<rows;++rowIndex){
        for(int colIndex = 1;colIndex<cols;++colIndex){
            int value;
            if(matrix[rowIndex][colIndex]=='1'){
                //check in that col
                //check in that row
                //check diagonally
                int row = checkRow(matrix,rowIndex,colIndex);
                int col = checkCol(matrix,rowIndex,colIndex);
                int prev = dp[rowIndex-1][colIndex-1];
                value = std::min(row,std::min(col,prev)) + 1;
            }
            else{
                value = 0;
            }
            dp[rowIndex][colIndex] = value;
            maxArea = std::max(maxArea,dp[rowIndex][colIndex]);
        }
    }
    return maxArea*maxArea;
}