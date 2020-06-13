#include<iostream>
#include<vector>
#include<queue>
#define mod 1000000007
int solve(int A, std::vector<int> &B){
    long long ans = 0;
    //use max Heap
    std::priority_queue<int> maxHeap(B.begin(),B.end());
    while(A--){
        int top = maxHeap.top();
        ans = (ans + (long long)top)%mod;
        maxHeap.pop();
        maxHeap.push(top/2);
    }
    return ans;
}
int main(){
    int N,A;
    std::cin>>N;
    std::vector<int> vec(N,0);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>A;
    int output = solve(A,vec);
    std::cout<<output<<std::endl;
    return 0;
}