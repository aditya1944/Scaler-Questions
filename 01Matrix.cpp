#include<vector>
#include<iostream>
#include<climits>
std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& matrix) {
    //traverse from top left;
    //while traversing top left for any cell having 1 check top and left 
    // and matrix[i][j] = std::min(matrix[i][j], std::min(matrix[i][j-1],matrix[i-1][j])+1);
    //traverse from bottom right;
    //matrix[i][j] = std::min(matrix[i][j], std::min(matrix[i][j+1],matrix[i+1][j])+1);
    //thats it;
    const int rows = matrix.size(),cols = matrix[0].size();
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            if(matrix[rowIndex][colIndex]){
                int upValue = INT_MAX,leftValue = INT_MAX;
                //check if upper cell exists
                if(rowIndex-1>=0 && matrix[rowIndex-1][colIndex]!=INT_MAX){
                    upValue = matrix[rowIndex-1][colIndex] + 1;
                }
                //check if left cell exists
                if(colIndex-1>=0 && matrix[rowIndex][colIndex-1]!=INT_MAX){
                    leftValue = matrix[rowIndex][colIndex-1]+1;
                }
                matrix[rowIndex][colIndex] = std::min(upValue,leftValue);
            }
        }
    }
    for(int rowIndex = rows-1;rowIndex>=0;--rowIndex){
        for(int colIndex = cols-1;colIndex>=0;--colIndex){
            if(matrix[rowIndex][colIndex]){
                int downValue = INT_MAX,rightValue = INT_MAX;
                //check if down cell exists
                if(rowIndex+1<rows && matrix[rowIndex+1][colIndex]!=INT_MAX){
                    downValue = matrix[rowIndex+1][colIndex] + 1;
                }
                //check if right cell exists
                if(colIndex+1<cols && matrix[rowIndex][colIndex+1]!=INT_MAX){
                    rightValue = matrix[rowIndex][colIndex+1]+1;
                }
                matrix[rowIndex][colIndex] = std::min(std::min(matrix[rowIndex][colIndex], downValue), rightValue );
            }
        }
    }
    return matrix;
}