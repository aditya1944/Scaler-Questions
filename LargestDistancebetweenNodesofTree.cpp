#include<iostream>
#include<vector>
#include<unordered_map>
void dfs(std::vector<std::vector<int> > &adjacencyList, int currNode, std::vector<bool> &visited, std::pair<int, int> &maxPair, int currDepth){
    visited[currNode] = true;
    for(int index = 0;index<adjacencyList[currNode].size();++index){
        int neighbourNode = adjacencyList[currNode][index];
        if(!visited[neighbourNode]){
            if(currDepth>maxPair.second){
                maxPair.second = currDepth;
                maxPair.first = currNode;
            }
            dfs(adjacencyList, neighbourNode, visited,maxPair, currDepth+1);
        }
    }
}
int solve(std::vector<int> &vec){
    //change the vec array
    /*for(int index = 0;index<vec.size();++index){
        vec[index]+=1;
    }*/
    //there is a link btween A[i] and i+1;
    //do dfs from 0
    std::vector<bool> visited(vec.size()+2,false);
    //make an adjacency List
    std::vector<std::vector<int> > adjacencyList(vec.size()+2);
    for(int index = 0;index<vec.size();++index){
        int startNode = vec[index]+1;
        int endNode = index+1;
        adjacencyList[startNode].push_back(endNode);
        adjacencyList[endNode].push_back(startNode);
    }
    //adjacency List is ready
    //do dfs on root Node and return farthest Node
    std::pair<int, int> maxPair;
    //{node, maxLength};
    dfs(adjacencyList, 0,visited,maxPair, 0);
    for(bool val: visited){
        val = false;
    }
    maxPair.second = -1;
    dfs(adjacencyList,maxPair.first,visited,maxPair,0);
    return maxPair.second;
}
int main(){

    return 0;
}