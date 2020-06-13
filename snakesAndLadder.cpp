#include<iostream>
#include<vector>
#include<queue>
int snakesAndLadders(std::vector<std::vector<int> >& board){
    const int n = board.size();
    std::vector<int> boardVector(n*n  + 1);
       std::vector<bool> visited(n*n + 1,false);
       int boardIndex = 1;
        bool flag = true;
        for(int rowIndex = n-1;rowIndex>=0;--rowIndex){
            if(flag){
                //traverse from left to right
                for(int colIndex = 0;colIndex<n;++colIndex){
                    boardVector[boardIndex] = board[rowIndex][colIndex];
                    ++boardIndex;
                }   
                flag = false;
            }
            else{
                flag = true;
                for(int colIndex = n-1;colIndex>=0;--colIndex){
                    boardVector[boardIndex] = board[rowIndex][colIndex];
                    ++boardIndex;
                }
            }
        }
        /*for(int val: boardVector){
            std::cout<<val<<" ";
        }*/
        int maxIndex = n*n;
        std::queue<int> q;
        q.push(1);
        visited[1] = true;
        int steps = 0;
        while(!q.empty()){
            int levelSize = q.size();
            while(levelSize--){
                int top = q.front();
                if(boardVector[top]!=-1){
                    top = boardVector[top];
                }
                if(top==maxIndex){
                    return steps;
                }
                q.pop();
                for(int num = 1;num<=6;++num){
                    if(top + num<=maxIndex){
                        //valid board Index
                        if(visited[top+num]==true){
                            return -1;
                        }
                        q.push(top + num);
                        visited[top + num] = true;
                    }
                }
            }
            ++steps;
        }
        return -1;
}
int main(){
    return 0;
}