#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
std::vector<int> solve(int A, std::vector<std::vector<int> > &B){

    //make an adjacencyList
    std::vector<std::vector<size_t> > adjacencyList(A+1);
    for(size_t index = 0;index<B.size();++index){
        int startVertex = B[index][0], endVertex = B[index][1];
        adjacencyList[startVertex].push_back(endVertex);
    }

    //there are A Nodes and B is edge 
    //maintain inorder degree of Nodes;
    std::vector<size_t> inDegree(A+1,0);
    //store all indegree of nodes;
    for(size_t edgeIndex = 0;edgeIndex<B.size();++edgeIndex){
        size_t endVertex = B[edgeIndex][1];
        ++inDegree[endVertex];
    }
    std::priority_queue<size_t,std::vector<size_t>,std::greater<size_t> > q;
    //store all vertex of indegree = 0 in queue;
    //priority queue is taken for minHeap
    //give least vertex
    for(int vertex = 1;vertex<=A;++vertex){
        if(inDegree[vertex]==0){
            q.push(vertex);
        }
    }
    std::vector<int> order(A);
    std::vector<bool> visited(A+1,false);
    while(!q.empty()){
        size_t currentVertex = q.top();
        q.pop();
        visited[currentVertex] = true;
        order.push_back(currentVertex);
        for(size_t neighbourVertex: adjacencyList[currentVertex]){
            if(visited[neighbourVertex]){
                //graph has cycle
                order.clear();
                return order;
            }
            --inDegree[neighbourVertex];
            if(inDegree[neighbourVertex]==0){
                q.push(neighbourVertex);
            }
        }
    }
    return order;
}