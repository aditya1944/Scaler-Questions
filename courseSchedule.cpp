#include<iostream>
#include<vector>
#include<unordered_set>
bool dfs(std::vector<std::vector<int> > &adjacencyList, int currVertex, std::vector<bool> &visited, std::unordered_set<size_t> &whiteSet, std::unordered_set<size_t> &greySet, std::unordered_set<size_t> &blackSet){
    visited[currVertex] = true;
    whiteSet.erase(currVertex);
    greySet.insert(currVertex);
    for(int neighbourVertexIndex = 0;neighbourVertexIndex<adjacencyList[currVertex].size();++neighbourVertexIndex){
        int neighbourVertex = adjacencyList[currVertex][neighbourVertexIndex];
        if(greySet.find(neighbourVertex)!=greySet.end()){
            return true;
        }
        else if(blackSet.find(neighbourVertex)==blackSet.end()){
            continue;
        }
        else if(dfs(adjacencyList,neighbourVertex,visited,whiteSet,greySet,blackSet)){
            return true;
        }
    }
    greySet.erase(currVertex);
    blackSet.insert(currVertex);
    return false;
}
int solve(int A, std::vector<int> &B, std::vector<int> &C){
    //make an adjacency List
    std::vector<std::vector<int> > adjacencyList(A+1);
    std::vector<bool> visited(A+1,false);
    std::unordered_set<size_t> whiteSet, blackSet, greySet;
    for(int index = 0;index<B.size();++index){
        int startVertex = B[index];
        int endVertex = C[index];
        adjacencyList[startVertex].push_back(endVertex);
        whiteSet.insert(startVertex);
        whiteSet.insert(endVertex);
    }
    for(int vertex = 1;vertex<A;++vertex){
        if(!visited[vertex]){
            if(dfs(adjacencyList,vertex,visited,whiteSet,blackSet,greySet)){
                return 0;
            }
        }
    }
    return 1;
}