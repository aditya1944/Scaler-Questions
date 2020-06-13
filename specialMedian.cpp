#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
int solve(std::vector<int> &A){
    //traverse left and traverse right
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int> ,std::greater<int> > minHeap;
    maxHeap.push(A[0]);
    double currMedian = A[0];
    for(int index = 1;index<A.size();++index){
        if(currMedian==(double)A[index]){
            return 1;
        }
        //comapre this element with top of maxHeap and decide where it will go
        if(maxHeap.top()>A[index]){
            //this element should stay in maxHeap only
            maxHeap.push(A[index]);
        }
        else{
            minHeap.push(A[index]);
        }
        //balance the array;
        int sizeDiff = std::abs((float)maxHeap.size()-minHeap.size());
        if(sizeDiff>1){
            //balancing is required
            if(maxHeap.size()>minHeap.size()){
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
            }
            else{
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
        }
        //trees are balanced
        //calculate median
        if(minHeap.size()==maxHeap.size()){
            currMedian = (double)minHeap.top() + (double)maxHeap.top();
            currMedian = currMedian/2;
        }
        else{
            if(minHeap.size()>maxHeap.size()){
                currMedian = minHeap.top();
            }
            else{
                currMedian = maxHeap.top();
            }
        }
    }
    //[1,4,5,6,7,9]
    while(!maxHeap.empty()){
        maxHeap.pop();
    }
    while(!minHeap.empty()){
        minHeap.pop();
    }
    std::reverse(A.begin(),A.end());
    maxHeap.push(A[0]);
    currMedian = A[0];
    for(int index = 1;index<A.size();++index){
        if(currMedian==(double)A[index]){
            return 1;
        }
        //comapre this element with top of maxHeap and decide where it will go
        if(maxHeap.top()>A[index]){
            //this element should stay in maxHeap only
            maxHeap.push(A[index]);
        }
        else{
            minHeap.push(A[index]);
        }
        //balance the array;
        int sizeDiff = std::abs((float)maxHeap.size()-minHeap.size());
        if(sizeDiff>1){
            //balancing is required
            if(maxHeap.size()>minHeap.size()){
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
            }
            else{
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
        }
        //trees are balanced
        //calculate median
        if(minHeap.size()==maxHeap.size()){
            currMedian = (double)minHeap.top() + (double)maxHeap.top();
            currMedian = currMedian/2;
        }
        else{
            if(minHeap.size()>maxHeap.size()){
                currMedian = minHeap.top();
            }
            else{
                currMedian = maxHeap.top();
            }
        }
    }
    return 0;
}