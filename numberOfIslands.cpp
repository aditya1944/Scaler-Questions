#include<iostream>
#include<vector>
void bfs(std::vector<std::vector<int> >& matx, std::vector<std::vector<bool> > &visited,int rowIndex,int colIndex){
    const int rows = matx.size(),cols = matx[0].size();
    visited[rowIndex][colIndex] = true;
    //check diagonally right down
    if((rowIndex+1<rows && colIndex+1<cols) && (matx[rowIndex+1][colIndex+1]==1 && visited[rowIndex+1][colIndex+1]==false)){
        bfs(matx,visited,rowIndex+1,colIndex+1);
    }
    //check diagonally right up
    if((rowIndex-1>=0 && colIndex+1<cols) && (matx[rowIndex-1][colIndex+1]==1 && visited[rowIndex-1][colIndex+1]==false)){
        bfs(matx,visited,rowIndex-1,colIndex+1);
    }
    //check right
    if((colIndex+1<cols) && (matx[rowIndex][colIndex+1]==1 && visited[rowIndex][colIndex+1]==false)){
        bfs(matx,visited,rowIndex,colIndex+1);
    }
    //check up
    if((rowIndex-1>=0) && (matx[rowIndex-1][colIndex]==1 && visited[rowIndex-1][colIndex]==false)){
        bfs(matx,visited,rowIndex-1,colIndex);
    }
    //check down //this condition is wrong
    if((rowIndex-1>=0) && (matx[rowIndex-1][colIndex]==1 && visited[rowIndex-1][colIndex]==false)){
        bfs(matx,visited,rowIndex-1,colIndex);
    }
    //check left
    if((colIndex-1>=0) && (matx[rowIndex][colIndex-1]==1 && visited[rowIndex][colIndex-1]==false)){
        bfs(matx,visited,rowIndex,colIndex-1);
    }
    //check diagonally left up
    if((rowIndex-1>=0 && colIndex-1>=0) && (matx[rowIndex-1][colIndex-1]==1 && visited[rowIndex-1][colIndex-1]==false)){
        bfs(matx,visited,rowIndex-1,colIndex-1);
    }
    //check diagonally left down
    if((rowIndex-1>=0 && colIndex+1<cols) && (matx[rowIndex-1][colIndex+1]==1 && visited[rowIndex-1][colIndex+1]==false)){
        bfs(matx,visited,rowIndex-1,colIndex+1);
    }
}
int solve(std::vector<std::vector<int> > &matx){
    std::vector<std::vector<bool> > visited = matx;
    int noOfIslands = 0;
    // in visited if 2 then visited 1 for not visited and 0 if there is no land
    for(int rowIndex = 0;rowIndex<matx.size();++rowIndex){
        for(int colIndex = 0;colIndex<matx.size();++colIndex){
            if(matx[rowIndex][colIndex]==1 && !visited[rowIndex][colIndex]){
                //do bfs
                bfs(matx,visited,rowIndex,colIndex);
                ++noOfIslands;
            }
        }
    }
    return noOfIslands;
}
int main(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<int> > matx(N,std::vector<int>(M,0));
    for(int rowIndex = 0;rowIndex<N;++rowIndex){
        for(int colIndex = 0;colIndex<M;++colIndex){
            std::cin>>matx[rowIndex][colIndex];
        }
    }
    int output = solve(matx);
    std::cout<<output<<std::endl;
    return 0;
}