#include<iostream>
#include<vector>
#include<queue>
#include<climits>
struct Node{
    int node;
    int distance;
};
int solve(int A,std::vector<std::vector<int> > &B, int C, int D){
    if(C==D){
        return 0;
    }
    //make an adjacency List
    std::vector<std::vector<int> > adjacencyList(2*A);
    for(int index = 0;index<B.size();++index){
        int startVertex = B[index][0];
        int endVertex = B[index][1];
        if(B[index][3]==1){
            adjacencyList[startVertex].push_back(endVertex);
            adjacencyList[endVertex].push_back(startVertex);
        }
        else{
            adjacencyList[startVertex].push_back(startVertex+A);
            adjacencyList[startVertex+A].push_back(startVertex);
            adjacencyList[endVertex].push_back(startVertex+A);
            adjacencyList[startVertex+A].push_back(endVertex);
        }
    }
    //adjacencyList is ready
    //now do bfs
    std::vector<bool> visited(A,false);
    std::queue<Node> q;
    visited[C] = true;
    q.push({C,0});
    while(!q.empty()){
        Node node = q.front();
        int currNode = node.node;
        q.pop();
        for(int index = 0;index<adjacencyList[currNode].size();++index){
            int neighbourNode = adjacencyList[currNode][index];
            if(!visited[neighbourNode]){
                /*if(neighbourNode==D){
                    return (currDistance + adjacencyList[currNode][index].second);
                }*/
                q.push({neighbourNode,node.distance+1});
                visited[neighbourNode] = true;
                if(neighbourNode==D){
                    return node.distance+1;
                }
            }
        }
    }
    return -1;
}
int main(){
    return 0;
}