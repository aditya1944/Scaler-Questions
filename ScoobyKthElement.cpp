#include<iostream>
#include<vector>
#include<queue>
std::vector<int> solve(int K,const std::vector<int> &vec){
    const int size = vec.size();
    std::vector<int> result(size,-1);
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
    for(int index = 0;index<vec.size();++index){
        if(minHeap.size()<K){
            minHeap.push(vec[index]);
            if(minHeap.size()==K){
                result[index] = minHeap.top();
            }
        }
        else{
            if(vec[index]>minHeap.top()){
                minHeap.pop();
                minHeap.push(vec[index]);
            }
            result[index] = minHeap.top();
        }
    }
    return result;
}