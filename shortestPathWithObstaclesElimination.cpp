#include<iostream>
#include<vector>
#include<queue>
struct Node{
    int row,col,r,distance;
};
int shortestPath(std::vector<std::vector<int>>& grid, int k) {
        //use bfs
        const int rows = grid.size(),cols = grid[0].size(),finalRow = rows-1,finalCol = cols-1;
        std::queue<Node> q;
        std::vector<std::vector<bool> > visited(rows,std::vector<bool>(cols,false));
        Node node;node.row = 0;node.col = 0;node.r = k,node.distance = 0;
        q.push(node);
        while(!q.empty()){
            int currRow = q.front().row;
            int currCol = q.front().col;
            int remainingWalls = q.front().r;
            int currDistance = q.front().distance;
            visited[currRow][currCol] = true;
            q.pop();
            if(currRow==finalRow && currCol == finalCol){
                return currDistance;
            }
            //move left 
            //move right
            //move up
            //move down
            
            //moving left 
            if(currCol-1>=0 && !visited[currRow][currCol-1]){
                //check if it is wall or empty
                if(grid[currRow][currCol-1]==1){
                    //it is wall
                    if(remainingWalls>0){
                        node.row = currRow;
                        node.col = currCol-1;
                        node.r = remainingWalls-1;
                        node.distance = currDistance+1;
                        q.push(node);
                    }
                }
                else{
                    // it is empty
                    node.row = currRow;
                    node.col = currCol-1;
                    node.r = remainingWalls;
                    node.distance = currDistance+1;
                    q.push(node);
                }
            }
            //moving right
            if(currCol+1<cols && !visited[currRow][currCol+1]){
                if(grid[currRow][currCol+1]==1){
                    //it is wall
                    if(remainingWalls>0){
                        node.row = currRow;
                        node.col = currCol+1;
                        node.r = remainingWalls-1;
                        node.distance = currDistance+1;
                        q.push(node);
                    }
                }
                else{
                    // it is empty
                    node.row = currRow;
                    node.col = currCol+1;
                    node.r = remainingWalls;
                    node.distance = currDistance+1;
                    q.push(node);
                }
            }
            //moving up
            if(currRow-1>=0 && !visited[currRow-1][currCol]){
                if(grid[currRow-1][currCol]==1){
                    //it is wall
                    if(remainingWalls>0){
                        node.row = currRow-1;
                        node.col = currCol;
                        node.r = remainingWalls-1;
                        node.distance = currDistance+1;
                        q.push(node);
                    }
                }
                else{
                    // it is empty
                    node.row = currRow-1;
                    node.col = currCol;
                    node.r = remainingWalls;
                    node.distance = currDistance+1;
                    q.push(node);
                }
            }
            //moving down
            if(currRow+1<rows && !visited[currRow+1][currCol]){
                if(grid[currRow+1][currCol]==1){
                    //it is wall
                    if(remainingWalls>0){
                        node.row = currRow+1;
                        node.col = currCol;
                        node.r = remainingWalls-1;
                        node.distance = currDistance+1;
                        q.push(node);
                    }
                }
                else{
                    // it is empty
                    node.row = currRow+1;
                    node.col = currCol;
                    node.r = remainingWalls;
                    node.distance = currDistance+1;
                    q.push(node);
                }
            }
        }
        return -1;
    }
int main(){
    int rows,cols,K;
    std::cin>>rows>>cols;
    std::vector<std::vector<int> >grid(rows,std::vector<int>(cols,0));
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            std::cin>>grid[rowIndex][colIndex];
        }
    }
    std::cin>>K;
    std::cout<<shortestPath(grid,K);
    return 0;
}