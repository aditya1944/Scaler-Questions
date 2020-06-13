#include<iostream>
#include<vector>
#include<queue>
int bfs(std::vector<std::vector<int> > &adjacencyList, int A){
    std::queue<int> q;
    q.push(1);
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        for(int node:adjacencyList[currentNode]){
            if(node==A){
                return 1;
            }
            q.push(node);
        }
    }
    return 0;
}

int solve(int A, std::vector<vector<int> > &B) {
    //find if path exists from node 1 to node A;
    std::vector<std::vector<int> > adjacencyList(A+1);
    for(int index = 0;index<B.size();++index){
        int startingPoint = B[index][0];
        int endingPoint = B[index][1];
        adjacencyList[startingPoint].push_back(endingPoint);
    }
    //adjacenecyList is ready
    //perform dfs from point 1
    int ifReachable = bfs(adjacencyList,A);
    return ifReachable;
}
int main(){
    return 0;
}