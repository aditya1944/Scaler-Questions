#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
bool dfs(std::vector<std::vector<size_t> > &adjacencyMatx, std::unordered_set<size_t> &whiteSet, std::unordered_set<size_t> &greySet, std::unordered_set<size_t> &blackSet,int currVertex){
    whiteSet.erase(currVertex);
    greySet.insert(currVertex);
    for(size_t neighbourVertex: adjacencyMatx[currVertex]){
        if(greySet.find(neighbourVertex)!=greySet.end()){
            return true;
        }
        if(blackSet.find(neighbourVertex)!=blackSet.end()){
            continue;
        }
        if(dfs(adjacencyMatx,whiteSet,greySet,blackSet,neighbourVertex)){
            return true;
        }
    }
    greySet.erase(currVertex);
    blackSet.insert(currVertex);
    return false;
}
int solve(int A,std::vector<std::vector<int> >&B){
    std::vector<bool> visited(A+1, false);
    //make an adjacency List
    std::vector<std::vector<size_t> > adjacencyList(A+1);
    for(int rowIndex = 0;rowIndex<B.size();++rowIndex){
        int startVertex = B[rowIndex][0];
        int endVertex = B[rowIndex][1];
        adjacencyList[startVertex].push_back(endVertex);
    }
    //adjacencyList is ready
    //use dfs
    std::unordered_set<size_t> whiteSet, greySet,blackSet;
    for(int vertex = 1;vertex<=A;++vertex){
        whiteSet.insert(vertex);
    }
    for(size_t vertex = 1;vertex<=A;++vertex){
        if(whiteSet.find(vertex)!=whiteSet.end()){
            if(dfs(adjacencyList,whiteSet,greySet,blackSet,vertex)){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    return 0;
}

