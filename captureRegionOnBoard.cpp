#include<iostream>
#include<vector>
void dfs(std::vector<std::vector<char> > &A, int rowIndex, int colIndex){
    A[rowIndex][colIndex]='-';
    const int rows = A.size(),cols = A[0].size();
    //move left right up down
    if(rowIndex-1>=0 && A[rowIndex-1][colIndex]=='O'){
        dfs(A,rowIndex-1,colIndex);
    }
    if(colIndex-1>=0&&A[rowIndex][colIndex-1]=='O'){
        dfs(A,rowIndex,colIndex-1);
    }
    if(rowIndex+1<rows && A[rowIndex+1][colIndex]=='O'){
        dfs(A,rowIndex+1,colIndex);
    }
    if(colIndex+1<cols &&A[rowIndex][colIndex+1]=='O'){
        dfs(A,rowIndex,colIndex+1);
    }
}
void solve(std::vector<std::vector<char> > &A){
    //do dfs from boundary which has 'O' value and mark them as '-'.
    //in the result we will reverse '-' as 'O' and mark 'O' as X
    
    //go top boundary
    //rowIndex = 0;
    const int rows = A.size(),cols = A[0].size();
    for(int colIndex = 0;colIndex<cols;++colIndex){
        if(A[0][colIndex]=='O'){
            dfs(A,0,colIndex);
        }
    }
    //go right boundary
    //colIndex = cols-1
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        if(A[rowIndex][cols-1]=='O'){
            dfs(A,rowIndex,cols-1);
        }
    }
    //go down boundary
    for(int colIndex = 0;colIndex<cols;++colIndex){
        if(A[rows-1][colIndex]=='O'){
            dfs(A,rows-1,colIndex);
        }
    }
    //go left boundary
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        if(A[rowIndex][0]=='O'){
            dfs(A,rowIndex,0);
        }
    }
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            if(A[rowIndex][colIndex]=='-'){
                A[rowIndex][colIndex]='O';
            }
            else if(A[rowIndex][colIndex]=='O'){
                A[rowIndex][colIndex]='X';
            }
        }
    }
    //return A;
}
int main(){
    return 0;
}