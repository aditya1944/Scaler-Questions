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
        for(auto neighbourNode: adjacencyMatrix[currentVertex]){
            if(!visited[neighbourNode.first]){
                int src = currentVertex,dest = neighbourNode.first,weight = neighbourNode.second;
                minPath[dest] = std::min(minPath[dest],minPath[src] + weight);
                minHeap.push({neighbourNode.first,neighbourNode.second});
            }
        }
        visited[currentVertex] = true;
    }
}
std::vector<int> solve(int A, std::vector<std::vector<int> > &B, int C){
    //A is total no. of nodes
    //C is  
    std::vector<std::vector<std::pair<int, int> > >adjacencyList(A);
    for(int index = 0;index<B.size();++index){
        int startVertex = B[index][0];
        int endVertex = B[index][1];
        int weight = B[index][2];
        adjacencyList[startVertex].push_back(std::pair<int, int>(endVertex, weight));
    }
    std::priority_queue<Node,std::vector<Node>, CompareNode> minHeap;
    minHeap.push({C,0});
    std::vector<int> minPath(A,INT_MAX);
    minPath[C] = 0;
    dikstra(adjacencyList,minPath, minHeap);
    return minPath;
}

int main(){
    return 0;
}

