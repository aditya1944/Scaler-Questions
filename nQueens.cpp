#include<iostream>
#include<vector>
bool isPossible(std::vector<std::vector<int> >board, int currRow, int currCol){
    //check diagonally left
    //check diagonally right
    //check up
    int i = currRow-1;
    int j = currCol-1;
    while(i>=0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        --i;
        --j;
    }
    //checked diagonally left
    i = currRow-1;
    j = currCol+1;
    while(i>=0 && j<board.size()){
        if(board[i][j]==1){
            return false;
        }
        --i;
        ++j;
    }
    //checked diagonally right
    i = currRow-1;
    j = currCol;
    while(i>=0){
        if(board[i][j]==1){
            return false;
        }
        --i;
    }
    return true;
}
bool helper(int currRow,std::vector<std::vector<int> >board ,std::vector<std::vector<std::string> >& result, int N){
    if(currRow==N){
        //print the board
        std::vector<std::string> temp1;
        for(auto &row: board){
            std::string temp = "";
            for(int &val:row){
                if(val==0){
                    temp+=".";
                }
                else{
                    temp+="Q";
                }
            }
            temp1.push_back(temp);
        }
        result.push_back(temp1);
        return true;
    }
    for(int colIndex = 0;colIndex<N;++colIndex){
        if(isPossible(board, currRow, colIndex)){
            //std::cout<<"jj1";
            board[currRow][colIndex] = 1;
            helper(currRow+1, board, result, N);
            board[currRow][colIndex] = 0;
        }
        else{
            //std::cout<<"jj";
        }
    }
}
std::vector<std::vector<std::string> > solve(int N){
    std::vector<std::vector<std::string> > returnValue;
    std::vector<std::vector<int> >board(N, std::vector<int>(N, 0)); 
    int currRow = 0;
    helper(currRow,board, returnValue, N);
    return returnValue;
}
int main(){
    int N;
    scanf("%d",&N);
    std::vector<std::vector<std::string> > output = solve(N); 
    for(auto x: output){
        for(auto y:x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}