#include<vector>
#include<queue>
#include<iostream>
struct Node{
    int row,col;
};
int solve(std::vector<std::vector<int> >&A){
    //use bfs
    std::queue<Node> q;
    //traverse full matrix and insert positions of rotten oranges in the queue
    const int rows = A.size(),cols = A[0].size();
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            if(A[rowIndex][colIndex]==2){
                Node node; node.row = rowIndex;node.col = colIndex;
                q.push(node);
            }
        }
    }
    int time = 0;
    while(!q.empty()){
        int noOfNodeatCurrentLevel = q.size();
        ++time;
        while(noOfNodeatCurrentLevel--){
            Node node = q.front();
            q.pop();
            int rowIndex = node.row,colIndex = node.col;
            //insert neighbouring nodes in queue;

            //1. up
            if(rowIndex-1>=0 && A[rowIndex-1][colIndex]==1){
                A[rowIndex-1][colIndex]=2;
                Node up; up.row = rowIndex-1;up.col = colIndex;
                q.push(up);
            }
            //2. down
            if(rowIndex+1<rows && A[rowIndex+1][colIndex]==1){
                A[rowIndex+1][colIndex]=2;
                Node down; down.row = rowIndex+1;down.col = colIndex;
                q.push(down);
            }
            //3. left
            if(colIndex-1>=0 && A[rowIndex][colIndex-1]==1){
                A[rowIndex][colIndex-1] = 2;
                Node left; left.row = rowIndex;left.col = colIndex-1;
                q.push(left);
            }
            //4.right
            if(colIndex+1<cols && A[rowIndex][colIndex+1]==1){
                A[rowIndex][colIndex+1] = 2;
                Node left; left.row = rowIndex;left.col = colIndex+1;
                q.push(left);
            }
        }
    }
    if(time==0){
        return -1;
    }
    for(auto vec: A){
        for(int val: vec){
            if(val==1){
                return -1;
            }
        }
    }
    return time;
}