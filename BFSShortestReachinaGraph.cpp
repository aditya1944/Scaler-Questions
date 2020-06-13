#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>

class Graph {
    private:
        std::vector<std::vector<int> > adjacencyList;
        int noOfVertex;
        int findMinVertex(std::vector<bool> &visited, std::vector<int> &distanceVector){
            int minVertex = -1;
            int minDist = INT_MAX;
            for(int vertex = 0;vertex<noOfVertex;++vertex){
                if(!visited[vertex]){
                    if(minDist>distanceVector[vertex]){
                        minDist = distanceVector[vertex];
                        minVertex = vertex;
                    }
                }
            }
            return minVertex;
        }
    public:
        Graph(int n) {
            noOfVertex = n;
            adjacencyList.resize(n);
        }
        void add_edge(int u, int v) {
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }
        
        std::vector<int> shortest_reach(int currentVertex) {
            std::vector<int> distanceVector(noOfVertex, INT_MAX);
            std::vector<bool> visited(noOfVertex,false);
            distanceVector[currentVertex] = 0;
            //apply dikstra algorithm
            while(1){
                //implement min Function
                currentVertex = findMinVertex(visited, distanceVector);
                if(currentVertex==-1){
                    break;
                }
                visited[currentVertex] = true;
                for(int adjacentVertex:adjacencyList[currentVertex]){
                    if(!visited[adjacentVertex]){
                        distanceVector[adjacentVertex] = std::min(distanceVector[adjacentVertex], distanceVector[currentVertex]+6);
                    }
                }
            }
            for(int vertex = 0;vertex<noOfVertex;++vertex){
                if(distanceVector[vertex]==INT_MAX){
                    distanceVector[vertex]=-1;
                }
            }
            return distanceVector;
        }
    
};

int main() {
    int queries;
    std::cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        std::cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        std::cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        std::cin >> startId;
        startId--;
        // Find shortest reach from node s
        std::vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                std::cout << distances[i] << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}

