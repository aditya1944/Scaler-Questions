#include<vector>
#include<iostream>
#include<stack>
#include<climits>
struct Node{
    int vertex;
    int distance;
};
std::pair<int, int> dfs(std::vector<std::vector<int> > adjacencyList, int rootNode){
    std::stack<Node> st;
    std::vector<bool>visited(adjacencyList.size(),false);
    int maxDistance = 0;
    int maxDistantNode = rootNode;
    Node node ;
    node.vertex = rootNode;
    node.distance = 0;
    st.push(node);
    while(!st.empty()){
        int currVertex = st.top().vertex;
        int currDistance = st.top().distance;
        st.pop();
        visited[currVertex] = true;
        for(int index = 0;index<adjacencyList[currVertex].size();++index){
            int neighbourVertex = adjacencyList[currVertex][index];
            if(!visited[neighbourVertex]){
                node.distance = currDistance+1;
                node.vertex = neighbourVertex;
                if(node.distance>maxDistance){
                    maxDistantNode = neighbourVertex;
                    maxDistance = node.distance;
                }
                st.push(node);
            }
        }
    }
    std::pair<int, int> returnValue;
    returnValue.first = maxDistantNode;
    returnValue.second = maxDistance;
    return returnValue;
}
int solve(std::vector<int> &A){
    //do dfs twice
    //first make adjacency List
    std::vector<std::vector<int> > adjacencyList(A.size());
    int rootNode;
    for(int vertex = 0;vertex<A.size();++vertex){
        if(A[vertex]==-1){
            rootNode = vertex;
        }
        else{
            int src = vertex;
            int dest = A[vertex];
            adjacencyList[src].push_back(dest);
            adjacencyList[dest].push_back(src);
        }
    }
    //do dfs from rootNode and count steps
    std::pair<int, int> p = dfs(adjacencyList,rootNode);
    p = dfs(adjacencyList,p.first);
    return p.second;
}