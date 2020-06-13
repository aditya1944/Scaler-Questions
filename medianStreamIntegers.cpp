#include<vector>
#include<queue>
#include<iostream>
std::vector<int> solve(std::vector<int> &stream) {
    std::priority_queue<int> maxHeap;
    std::priority_queue<int,std::vector<int>,std::greater<int> > minHeap;
    const int streamSize = stream.size();
    std::vector<int> result(streamSize);
    minHeap.push(stream[0]);
    result[0]=stream[0];
    for(int index = 1;index<streamSize;++index){
        //1. compare with minHeap first Element
        //2. insert into respective heap
        //3. now balance the heap;
        //4. find median
        //std::cout<<index<<" ";
        int currNum = stream[index];
        if(currNum<minHeap.top()){
            maxHeap.push(currNum);
        }
        else{
            minHeap.push(currNum);
        }
        int sizeDiff = minHeap.size() - maxHeap.size();
        if(sizeDiff<0){
            sizeDiff = sizeDiff*-1;
        }
        if(sizeDiff>1){
            //balancing is required
            if(minHeap.size()>maxHeap.size()){
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
            else{
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
            }
        }
        //check size
        int currMedian;
        if(minHeap.size()==maxHeap.size()){
            currMedian = maxHeap.top();
        }
        else{
            if(maxHeap.size()>minHeap.size()){
                currMedian = maxHeap.top();
            }
            else{
                currMedian = minHeap.top();
            }
        }
        result[index] = currMedian;
    }
    return result;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> stream(N);
    for(int index = 0;index<N;++index){
        std::cin>>stream[index];
    }
    std::vector<int> output = solve(stream);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}