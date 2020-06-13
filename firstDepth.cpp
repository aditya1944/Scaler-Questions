#include<iostream>
#include<vector>
#include<queue>
int bfs(std::vector<std::vector<int> > &adjacencyList, const int B,const int C, int noOfNodes){
    std::vector<bool> visited(noOfNodes+1,false);
    std::queue<int> q;
    q.push(C);
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        visited[currentNode] = true;
        //traverse all its neighbours and store it in queue
        for(int val: adjacencyList[currentNode]){
            if(val==B){
                return 1;
            }
            if(!visited[val]){
                q.push(val);
            }
        }
    }
    return 0;
}
int solve(std::vector<int> &A,const int B,const int C){
    //use dfs
    //start from C and reach B
    //make a adjacency List
    std::vector<std::vector<int> > adjacencyList(A.size()+1);
    for(int index = 0;index<A.size();++index){
        int startVertex = A[index];
        int endVertex = index + 1;
        adjacencyList[startVertex].push_back(endVertex);
    }
    //use dfs on adjacencyList
    
    int ifReachable = bfs(adjacencyList,B,C,A.size());
    return ifReachable;
}
int main(){
    int N,B,C;
    std::cin>>N;
    std::vector<int> A(N);
    for(int index = 0;index<N;++index){
        std::cin>>A[index];
    }
    std::cin>>B>>C;
    int output = solve(A,B,C);
    std::cout<<output<<std::endl;
    return 0;
}