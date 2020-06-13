#include<iostream>
#include<vector>
#include<climits>
#include<queue>
struct Node{
    int row,col,distance;
};
std::vector<std::vector<int> > solve(std::vector<std::vector<int> >&A){
    //use bfs on every Node which value is 1;
    const int rows = A.size(),cols = A[0].size();
    std::vector<std::vector<int> > returnValue(rows,std::vector<int>(cols,0)),visited(rows,std::vector<int>(cols,0));
    std::queue<Node> q;
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            if(A[rowIndex][colIndex]==1){
                Node node;
                node.row = rowIndex;
                node.col = colIndex;
                node.distance = 0;
                q.push(node);
                visited[rowIndex][colIndex] = 1;
            }
        }
    }
    //std::cout<<q.size();
    while(!q.empty()){
        int currLevelSize = q.size();
        while(currLevelSize--){
            Node currNode = q.front();
            q.pop();
            int rowIndex = currNode.row,colIndex = currNode.col,distance = currNode.distance;
            //check left right up and down of that node
            //checking up
            if((rowIndex-1>=0 && A[rowIndex-1][colIndex]==0) && !visited[rowIndex-1][colIndex]){
                Node up;
                up.row = rowIndex-1;
                up.col = colIndex;
                up.distance = distance+1;
                q.push(up);
                visited[rowIndex-1][colIndex] = 1;
            }
            //checking right
            if((colIndex+1<cols && A[rowIndex][colIndex+1]==0) && !visited[rowIndex][colIndex+1]){
                Node right;
                right.row = rowIndex;
                right.col = colIndex+1;
                right.distance = distance+1;
                q.push(right);
                visited[rowIndex][colIndex+1] = 1;
            }
            //checking down
            if((rowIndex+1<rows && A[rowIndex+1][colIndex]==0) && !visited[rowIndex+1][colIndex]){
                Node down;
                down.row = rowIndex+1;
                down.col = colIndex;
                down.distance = distance+1;
                q.push(down);
                visited[rowIndex+1][colIndex] = 1;
            }
            //checking left
            if((colIndex-1>=0 && A[rowIndex][colIndex-1]==0) && !visited[rowIndex][colIndex-1]){
                Node left;
                left.row = rowIndex;
                left.col = colIndex;
                left.distance = distance+1;
                q.push(left);
                visited[rowIndex][colIndex-1] = 1;
            }
            returnValue[currNode.row][currNode.col] = distance;
            A[currNode.row][currNode.col] = 1;
        }
    }
    return returnValue;
}
int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<int> > matx(N,std::vector<int>(M,0));
    for(int rowIndex = 0;rowIndex<matx.size();++rowIndex){
        for(int colIndex = 0;colIndex<M;++colIndex){
            std::cin>>matx[rowIndex][colIndex];
        }
    }
    matx = solve(matx);
    for(auto vec:matx){
        for(int val: vec){
            std::cout<<val<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}