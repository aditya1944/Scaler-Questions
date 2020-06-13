#include<iostream>
#include<vector>
#include<queue>
void bfs(std::vector<std::vector<int> >&adjacencyList, std::vector<bool> &visited){
    int currentVertex = 1;
    int minLength = 0;
    std::queue<int> q;
    q.push(currentVertex);
    while(!q.empty()){
        currentVertex = q.front();
        q.pop();
        visited[currentVertex] = true;
        for(auto adjacentVertex: adjacencyList[currentVertex]){
            if(adjacentVertex==6){
                std::cout<<minLength;
                return;
            } 
            q.push(adjacentVertex);
        }
        ++minLength;
    }
}
int main(){
    std::vector<std::vector<int> >adjacencyList(7);
    adjacencyList[1].push_back(2);
    adjacencyList[2].push_back(3);
    adjacencyList[2].push_back(1);
    adjacencyList[2].push_back(5);
    adjacencyList[3].push_back(1);
    adjacencyList[3].push_back(4);
    adjacencyList[3].push_back(6);
    adjacencyList[4].push_back(3);
    adjacencyList[5].push_back(2);
    adjacencyList[6].push_back(3);
    std::vector<bool> visited(7, false);
    bfs(adjacencyList, visited);
    return 0;
}