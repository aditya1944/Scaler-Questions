#include<iostream>
#include<vector>
void bfs(std::vector<std::string> & A, int rowIndex, int colIndex){
    A[rowIndex][colIndex] = 'O';
    //move left , right, up and down
    //moving up 
    if(rowIndex-1>=0 && A[rowIndex-1][colIndex]=='X'){
        bfs(A,rowIndex-1,colIndex);
    }
    //moving down
    if(rowIndex+1<A.size() && A[rowIndex+1][colIndex]=='X'){
        bfs(A,rowIndex+1, colIndex);
    }
    //moving left
    if(colIndex-1>=0 && A[rowIndex][colIndex-1]=='X'){
        bfs(A,rowIndex,colIndex-1);
    }
    //moving right
    if(colIndex+1 < A[rowIndex].size() && A[rowIndex][colIndex+1]=='X'){
        bfs(A,rowIndex,colIndex+1);
    }
}
int solve(std::vector<std::string> & A){
    //find connected components
    //'X' means shape
    //'Y' means void
    /*std::vector<std::string> visited = A;
    for(int rowIndex = 0;rowIndex<A.size();++rowIndex){
        for(int colIndex = 0;colIndex<A[rowIndex].size();++colIndex){
            if(visited[rowIndex][colIndex]=='X'){
                visited[rowIndex][colIndex] = '0';
            }
        }
    }*/
    int count = 0;
    for(int rowIndex = 0;rowIndex<A.size();++rowIndex){
        for(int colIndex = 0;colIndex<A[rowIndex].size();++colIndex){
            //if(A[rowIndex][colIndex]=='X' && visited[rowIndex][colIndex]=='0'){
            if(A[rowIndex][colIndex]=='X'){
                bfs(A,rowIndex,colIndex);
                ++count;
            }
        }
    }
    return count;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}