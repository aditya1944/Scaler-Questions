#include<iostream>
#include<vector>
#include<queue>
struct Node{
    int vertex;
    int time;
};
int solve(const int A,const std::vector<int> &startVertex,const std::vector<int> &endVertex){
    // 1  1  2
    // 2  5  4
    //make an adjacency List
    std::vector<std::vector<int> >adjacencyList;
    const int n = startVertex.size();
    for(int index = 0;index<n;++index){
        adjacencyList[startVertex[index]].push_back(endVertex[index]);
    }
    //adjacencyList is ready
    //do bfs on adjacencyList
    std::queue<Node> q;
    Node node;
    node.vertex = 1;
    node.time = 0;
    q.push(node);
    int maxTime = 0;
    while(!q.empty()){
        Node topNode = q.front();
        int topVertex = topNode.vertex;
        int currTime = topNode.time;
        q.pop();
        for(int neighbourVertex: adjacencyList[topVertex]){
            node.vertex = neighbourVertex;
            node.time = currTime+1;
            maxTime = std::max(maxTime,node.time);
            q.push(node);
            ++currTime;
        }
    }
    return maxTime;
}