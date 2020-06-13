#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
UndirectedGraphNode * cloneGraph(UndirectedGraphNode* node){
    //1. do bfs on node
    //2. do
    UndirectedGraphNode* head = node;
    std::queue<UndirectedGraphNode*> q;
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashMap;
    q.push(node);
    UndirectedGraphNode* cloneNode;
    cloneNode = new UndirectedGraphNode(node->label);
    hashMap[node] = cloneNode;
    while(!q.empty()){
        UndirectedGraphNode* currNode = q.front();
        std::vector<UndirectedGraphNode*> neighbours = currNode->neighbors;
        for(int index = 0;index<neighbours.size();++index){
            node = neighbours[index];
            if(hashMap[node]){
                //the current neighbour node is not inserted in the hashMap
                cloneNode = new UndirectedGraphNode(node->label);
                hashMap[node] = cloneNode;
            }
            (hashMap[currNode])->neighbors.push_back(hashMap[node]);
        }
    }
    return hashMap[head];
}
int main(){
    return 0;
}