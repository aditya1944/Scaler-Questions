#include<iostream>
#include<vector>
#include<queue>
struct Node{
    int row,col,distance,direction;
};
//directions is -2,   -1 , 1,    2;
//              right up   left  bottom
int solve(std::vector<std::vector<int> > &A, std::vector<int> &B, std::vector<int> &C){
    const int finalRow = C[0], finalCol = C[1];
    const int row = A.size(),col = A[0].size();
    std::vector<std::vector<bool> > visited(row, std::vector<bool>(col,false));
    Node node;
    node.row = B[0];
    node.col = B[1];
    node.distance = 0;
    std::queue<Node> q;
    q.push(node);
    while(!q.empty()){
        Node currNode  = q.front();
        int currRow = currNode.row;
        int currCol = currNode.col;
        int currDistance = currNode.distance;
        int currDirection = currNode.direction;
        q.pop();
        //go top bottom left right
        //going top 
        if((currRow-1>=0 && A[currRow-1][currCol]!=1) && !visited[currRow-1][currCol]){
            node.row = currRow-1;
            node.col = currCol;
            node.distance = currDistance + 1;
            if(node.row==finalRow && node.col==finalCol){
                return node.distance;
            }
            q.push(node);
            visited[currRow-1][currCol] = true;
        }
        //going bottom
        if(((currRow+1)<row && A[currRow+1][currCol]!=1) && !visited[currRow+1][currCol]){
            node.row = currRow+1;
            node.col = currCol;
            node.distance = currDistance + 1;
            if(node.row==finalRow && node.col==finalCol){
                return node.distance;
            }
            q.push(node);
            visited[currRow+1][currCol] = true;
        }
        //going left
        if(((currCol-1)>=0 && A[currRow][currCol-1]!=1) && !visited[currRow][currCol-1]){
            node.row = currRow;
            node.col = currCol-1;
            node.distance = currDistance + 1;
            if(node.row==finalRow && node.col==finalCol){
                return node.distance;
            }
            q.push(node);
            visited[currRow][currCol-1] = true;
        }
        //going right
        if(((currCol+1)<col && A[currRow][currCol+1]!=1) && !visited[currRow][currCol+1]){
            node.row = currRow;
            node.col = currCol+1;
            node.distance = currDistance + 1;
            if(node.row==finalRow && node.col==finalCol){
                return node.distance;
            }
            q.push(node);
            visited[currRow][currCol+1] = true;
        }
    }
    return -1;
}
int main(){
    return 0;
}