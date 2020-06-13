#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
int bfs(std::vector<std::vector<int> >&adjacencyList, int currentVertex,std::vector<bool> &visited){
    int A = visited.size();
    std::vector<int> color(A,-1);
    std::queue<int> q;
    color[0] = 1;
    q.push(0);
    while(!q.empty()){
        int currentVertex = q.front();
        //currentVertex is already colored
        visited[currentVertex] = true;
        q.pop();
        for(int index = 0;index<adjacencyList[currentVertex].size();++index){
            int neighbourVertex = adjacencyList[currentVertex][index];
            if(color[neighbourVertex]==-1){
                //neighbourVertex is not colored
                color[neighbourVertex] = color[currentVertex]^1;
            }
            else{
                //neighbourVertex is colored
                if(color[neighbourVertex]==color[currentVertex]){
                    return 0;
                }
            }
            if(!visited[neighbourVertex])
                q.push(neighbourVertex);
        }
    }
    return 1;
}

int solve(int A,const std::vector<std::vector<int> >&B){
    //make adjacency List 
    std::vector<std::vector<int> >adjacencyList(A);
    for(int index = 0;index<B.size();++index){
        int startVertex = B[index][0],endVertex = B[index][1];
        adjacencyList[startVertex].push_back(endVertex);
        adjacencyList[endVertex].push_back(startVertex);
    }
    std::vector<bool> visited(A,false);
    for(int vertex = 0;vertex<A;++vertex){
        if(!visited[vertex]){
            if(bfs(adjacencyList, vertex, visited)==0){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    std::vector<int> vec;
    return 0;
}