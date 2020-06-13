#include<iostream>
#include<queue>
struct Node{
    int currVal,originalVal;
};
struct compare{
    bool operator()(Node& n1, Node& n2){
        //make a minHeap
        return n1.originalVal + n1.currVal>n2.originalVal+n2.currVal;
    }
};
int solve(const std::vector<int> &vec, int B){
    std::priority_queue<Node, std::vector<Node>,compare> minHeap;
    for(int index = 0;index<vec.size();++index){
        Node node;
        node.currVal = node.originalVal = vec[index];
        minHeap.push(node);
    }
    while(B--){
        Node node = minHeap.top();
        minHeap.pop();
        node.currVal+=node.originalVal;
        minHeap.push(node);
    }
    return minHeap.top().currVal;
}