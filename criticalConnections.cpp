#include<vector>
#include<iostream>
void dfs(const std::vector<std::vector<int> >&adjacencyMatrix, int currVertex, std::vector<bool> &visited, int parentVertex, int discoveryTime,std::vector<int> &lowTime, std::vector<std::vector<int> > &returnValue){
    visited[currVertex] = true;
    lowTime[currVertex] = discoveryTime;
    //childCount is only for head
    for(const int &neighbourVertex: adjacencyMatrix[currVertex]){
        if(neighbourVertex==parentVertex){
            continue;
        }
        else if(visited[neighbourVertex]){
            //this neighbourVertex has been visited;
            //updating the low time
            lowTime[currVertex] = std::min(lowTime[currVertex],lowTime[neighbourVertex]);
        }
        else{
            //neighbour vertex is not visited
            dfs(adjacencyMatrix,neighbourVertex,visited,currVertex,discoveryTime+1,lowTime,returnValue);
            if(discoveryTime<lowTime[neighbourVertex]){
                //this point is articulation point;
                //there exists no back edge 
                std::vector<int> bridge = {currVertex, neighbourVertex};
                returnValue.push_back(bridge);
            }
            else{
                lowTime[currVertex] = std::min(lowTime[currVertex],lowTime[neighbourVertex]);
            }
        }
    }
}
std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
    //make an adjacency Matrix
    std::vector<std::vector<int> > adjacencyMatrix(n);
    for(const auto& vec: connections){
        adjacencyMatrix[vec[0]].push_back(vec[1]);
        adjacencyMatrix[vec[1]].push_back(vec[0]);
    }
    std::vector<bool> visited(n,false);
    std::vector<std::vector<int> > returnValue;
    std::vector<int> lowTime(n);
    for(int vertex = 0;vertex<n;++vertex){
        if(!visited[vertex]){
            //do dfs at this vertex
            int parentVertex = -1;
            int discoveryTime = 0;
            dfs(adjacencyMatrix,vertex,visited,parentVertex,discoveryTime,lowTime,returnValue);
        }
        //start dfs traversal at this node;
    }
    return returnValue;
}
int main(){
    return 0;
}