#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
struct HeapNode{
    int AIndex;
    int BIndex;
    int val;
};
struct compare{
    bool operator()(const HeapNode &h1, const HeapNode &h2){
        return h1.val<h2.val;
    }
};
struct HASH{
  size_t operator()(const std::pair<int,int>&x)const{
    return std::hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
std::vector<int> solve(std::vector<int> &A, std::vector<int> &B) {
    std::sort(A.begin(),A.end());
    std::sort(B.begin(),B.end());
    std::vector<int> result(A.size());
    std::priority_queue<HeapNode,std::vector<HeapNode>, compare> maxHeap;
    std::unordered_set<std::pair<int, int>,HASH> hash;
    HeapNode heapNode;
    heapNode.BIndex = heapNode.AIndex = A.size()-1;
    heapNode.val = A[A.size()-1] + B[B.size()-1];
    maxHeap.push(heapNode);
    hash.insert({A.size()-1,B.size()-1});
    int index = 0;
    while(!maxHeap.empty() && index<result.size()){
        heapNode = maxHeap.top();
        maxHeap.pop();
        HeapNode h1,h2;
        h1.AIndex = heapNode.AIndex-1;
        h1.BIndex = heapNode.BIndex;
        h1.val = A[h1.AIndex] + B[h1.BIndex];
        h2.AIndex = heapNode.AIndex;
        h2.BIndex = heapNode.BIndex-1;
        h2.val = A[h2.AIndex] + B[h2.BIndex];
        //use hash condition here later
        if(hash.find({h1.AIndex,h1.BIndex})==hash.end()){
            maxHeap.push(h1);
            hash.insert({h1.AIndex,h1.BIndex});
        }
        if(hash.find({h2.AIndex,h2.BIndex})==hash.end()){
            maxHeap.push(h2);
            hash.insert({h2.AIndex,h2.BIndex});
        }
        result[index] = heapNode.val;
        ++index;
    }
    return result;
}