#include<vector>
#include<queue>
#include<iostream>
struct Node{
    int row,col;
};
int solve(std::vector<std::vector<int> >&grid){
    //use bfs
    const int rows = grid.size(),cols = grid[0].size();
    //use bfs
    std::queue<Node> q;
    //first insert all the rotten oranges index
    bool flag = false;
    //flag is just to check if there is any fresh oranges or not
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            int status = grid[rowIndex][colIndex];
            if(status==2){
                //this orange is rotten
                q.push({rowIndex,colIndex});
            }
            if(status==1){
                flag = true;
            }
        }
    }
    if(!q.size()){
        //there is no rotten oranges
        if(flag){
            return -1;
        }
        return 0;
    }
    int time = 0;
    std::vector<std::pair<int, int> > dirs = {{0,-1},{-1,0},{0,1},{1,0}};
    while(!q.empty()){
        int size = q.size();
        while(size--){
            //check all direction of rotten oranges and insert it in q
            Node node = q.front();
            q.pop();
            for(auto dir: dirs){
                int neighbourRow = node.row + dir.first;
                int neighbourCol = node.col + dir.second;
                if(neighbourRow>=0 && neighbourCol>=0 && neighbourRow<rows && neighbourCol<cols){
                    int status = grid[neighbourRow][neighbourCol];
                    if(status==1){
                        q.push({neighbourRow,neighbourCol});
                        grid[neighbourRow][neighbourCol] = 2;
                    }
                }
            }
        }
        ++time;
    }
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            int status = grid[rowIndex][colIndex];
            if(status==1){
                return -1;
            }
        }
    }
    return time-1;
}