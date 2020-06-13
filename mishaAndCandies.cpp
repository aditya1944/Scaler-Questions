#include<iostream>
#include<vector>
#include<queue>
int solve(std::vector<int> &A,int B){
    int ans = 0;
    std::priority_queue<int, std::vector<int>,std::greater<int> > minHeap(A.begin(),A.end()); 
    while(minHeap.size()>1){
        int top = minHeap.top();
        if(top>B){
            minHeap.pop();
        }
        else{
            minHeap.pop();
            int half = top/2;
            ans+=half;
            int secondTop = minHeap.top();
            int remaining = top - half;
            minHeap.push(remaining);
        }
    }
    if(minHeap.top>B){
        minHeap.pop();
    }
    else{
        ans+=(minHeap.top()/2);
    }
    return ans;
}
int main(){
    int N,B;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>B;
    int output = solve(vec,B);
    std::cout<<output<<std::endl;
    return 0;
}