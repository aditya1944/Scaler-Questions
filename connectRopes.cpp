#include<iostream>
#include<vector>
#include<queue>
int solve(const std::vector<int> &A){
    std::priority_queue <int, std::vector<int>, std::greater<int> > minHeap(A.begin(),A.end()); 
    while(minHeap.size()>1){
        int firstMax = minHeap.top();
        minHeap.pop();
        int secondMax = minHeap.top();
        minHeap.pop();
        minHeap.push(firstMax + secondMax);
    }
    return minHeap.top();
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
}