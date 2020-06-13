#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
int solve(std::vector<int> &A, int B){
    //std::priority_queue<int, std::vector<int>,std::greater<int> > minHeap(A.begin(),A.end());
    std::make_heap(A.begin(),A.end(),std::greater<int>());
    //now A is minHeap
    while(B){
        int front = A.front();
        if(front>0){
            break;
        }
        std::pop_heap(A.begin(),A.end(),std::greater<int>());
        A.pop_back();
        front = front*-1;
        A.push_back(front);
        std::push_heap(A.begin(),A.end(),std::greater<int>());
        --B;
    }
    /*for(int index = 0;index<A.size();++index){
        std::cout<<A[index]<<" ";
    }*/
    if(B%2!=0){
        int top = A.front();
        top = top*-1;
        std::pop_heap(A.begin(),A.end(),std::greater<int>());
        A.pop_back();
        int sum = top;
        for(int index = 0;index<A.size();++index){
            sum+=A[index];
        }
        return sum;
    }
    int sum = 0;
    for(int index = 0;index<A.size();++index){
        sum+=A[index];
    }
    return sum;
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