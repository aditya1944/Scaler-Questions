#include<iostream>
#include<vector>
void dfs(const std::vector<std::vector<int> >& adjacencyList, int currNode,std::vector<bool> &visited){
    visited[currNode] = true;
    for(int index = 0;index<adjacencyList[currNode].size();++index){
        int neighbour = adjacencyList[currNode][index];
        if(!visited[neighbour]){
            dfs(adjacencyList,neighbour,visited);
        } 
    }
}
int solve(std::vector<std::string> & A){
    //1. check if indegree and outdegree for every vertex is same or not
    //2. graph is strongly connected

    //make a adjacencyList
    std::vector<int> inDegree(26,0),outDegree(26,0);
    std::vector<bool> mark(26,false);
    std::vector<std::vector<int> >adjacencyList(26);
    for(int index = 0;index<A.size();++index){
        int startVertex = A[index].front() - 'a';
        int endVertex = A[index].back() - 'a';
        mark[startVertex] = mark[endVertex] = true;
        //update indegree of endVertex and outdegree of startVertex
        ++inDegree[endVertex];
        ++outDegree[startVertex];
        //make a edge
        adjacencyList[startVertex].push_back(endVertex);
    }
    //adjacency List is ready
    for(int index = 0;index<26;++index){
        if(inDegree[index]!=outDegree[index]){
            return 0;
        }
    }
    std::vector<bool> visited(26,false);
    dfs(adjacencyList, A[0].front()-'a',visited);
    for(int index = 0;index<26;++index){
        if(mark[index] && !visited[index]){
            return 0;
        }
    }
    return 1;
}