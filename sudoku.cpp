#include<iostream>
#include<vector>
bool findEmptyLocation(std::vector<std::vector<int> >&matx, int &row, int &col){
    //returns true if found empty location else returns false;
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(matx[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool isPossible(std::vector<std::vector<int> >&matx, int row, int col,int num){
    //check in row
    for(int col1  = 0;col1<9;++col1){
        if(matx[row][col1]==num){
            return false;
        }
    }
    //check in col
    for(int row1 =0;row1<9;++row1){
        if(matx[row1][col]==num){
            return false;
        }
    }
    //check in grid
    int gridRow = row - (row%3);
    int gridCol = col - (col%3);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(matx[gridRow + i][gridCol+j]==num){
                return false;
            }
        }
    }
    return true;
}
bool helper(std::vector<std::vector<int> >&sudoku){
    int row, col;
    if(!findEmptyLocation(sudoku,row,col)){
        return true;
    }
    for(int num = 1; num<10;++num){
        if(isPossible(sudoku,row, col,num)){
            sudoku[row][col] = num;
            if(helper(sudoku)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
} 
void solve(std::vector<std::vector<char> >&A){
    //make a number board
    std::vector<std::vector<int> >sudoku(9,std::vector<int>(9,0));
    for(int rowIndex = 0;rowIndex<9;++rowIndex){
        for(int colIndex = 0;colIndex<9;++colIndex){
            if(A[rowIndex][colIndex]=='.'){
                sudoku[rowIndex][colIndex] = 0;
            }
            else{
                int number = A[rowIndex][colIndex] - '0';
                sudoku[rowIndex][colIndex] =  number;
            }
            
        }
    }
    helper(sudoku);
    for(int row = 0;row<9;++row){
        for(int col = 0;col<9;++col){
            std::cout<<sudoku[row][col];//<<" ";
        }
        //std::cout<<std::endl;
    }
}
int main(){
    std::vector<std::vector<char> >board(9,std::vector<char>(9,'.'));
    for(int rowIndex = 0;rowIndex<9;++rowIndex){
        for(int colIndex = 0;colIndex<9;++colIndex){
            std::cin>>board[rowIndex][colIndex];
        }
    }
    solve(board);
    return 0;
}