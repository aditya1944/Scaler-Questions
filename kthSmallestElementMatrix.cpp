#include<iostream>
#include<vector>
#include<queue>
int solve(const std::vector<std::vector<int> > &A, int B){
    std::priority_queue<int> maxHeap;
    int ans;
    const int rows = A.size(),cols = A[0].size();
    for(int rowIndex = 0;rowIndex<rows;++rowIndex){
        for(int colIndex = 0;colIndex<cols;++colIndex){
            int currElement = A[rowIndex][colIndex];
            if(maxHeap.size()<B){
                maxHeap.push(currElement);
            }
            else{
                if(currElement>maxHeap.top()){
                    
                }
                else{
                    maxHeap.push(currElement);
                }
            }
        }
    }
    ans = maxHeap.top();
    return ans;
}