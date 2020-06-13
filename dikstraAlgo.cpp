#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
struct Node{
    int vertex;
    int distance;
};
struct CompareNode{
    bool operator()(const Node& n1, const Node& n2){
        return n1.distance>n2.distance;
    }
};
void dikstra(std::vector<std::vector<std::pair<int,int> > >& adjacencyMatrix, std::vector<int> &minPath, std::priority_queue<Node,std::vector<Node>, CompareNode> &minHeap){
    std::vector<bool> visited(adjacencyMatrix.size(),false);
    while(!minHeap.empty()){
        Node node = minHeap.top();
        minHeap.pop();
        int currentVertex = node.vertex;
        for(int index = 0;index<adjacencyMatrix[currentVertex].size();++index){
            if(!visited[adjacencyMatrix[currentVertex][index].first]){
                int src = currentVertex,dest = adjacencyMatrix[currentVertex][index].first,weight = adjacencyMatrix[currentVertex][index].second;
                minPath[dest] = std::min(minPath[dest],minPath[src] + weight);
                Node neighbourNode;
                neighbourNode.vertex = dest;
                neighbourNode.distance = minPath[dest];
                minHeap.push(neighbourNode);
            }
        }
        visited[currentVertex] = true;
    }
}
std::vector<int> solve(int A, std::vector<std::vector<int> > &B, int C){
    std::vector<std::vector<std::pair<int, int> > >adjacencyList(A);
    for(int index = 0;index<B.size();++index){
        int startVertex = B[index][0];
        int endVertex = B[index][1];
        int weight = B[index][2];
        adjacencyList[startVertex].push_back(std::pair<int, int>(endVertex, weight));
    }
    std::priority_queue<Node,std::vector<Node>, CompareNode> minHeap;
    for(int vertex = 0;vertex<A;++vertex){
        Node n;
        n.vertex = vertex;
        n.distance = INT_MAX;
        if(vertex==C){
            n.distance = 0;
        }
        minHeap.push(n);
    }
    std::vector<int> minPath(A,INT_MAX);
    minPath[C] = 0;
    dikstra(adjacencyList,minPath, minHeap);
    return minPath;
}

int main(){
    return 0;
}

