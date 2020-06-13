#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
std::vector<int> solve(std::vector<int> &A){
    std::vector<int> maxHeap,minHeap,ans(A.size());
    maxHeap.push_back(A[0]);
    maxHeap.push_back(A[1]);
    minHeap.push_back(A[0]);
    minHeap.push_back(A[1]);
    for(int index= 2;index<A.size();++index){
        int currElement = A[index];
        maxHeap.push_back(A[index]);
        minHeap.push_back(A[index]);
        std::sort(maxHeap.begin(),maxHeap.end());
        std::sort(minHeap.begin(),minHeap.end());
        //two possiblities.
        //one possiblity
        int p1 = maxHeap[0] * maxHeap[1] * maxHeap[2];
        int p2 = minHeap[0] * minHeap[1] * maxHeap[0];
        ans[index] = (p1>=p2)?p1:p2;
        if(maxHeap.size()>3){
            maxHeap.pop_back();
        }
        if(minHeap.size()>3){
            minHeap.pop_back();
        }
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
    auto output = solve(vec);
    for(int index = 0;index<vec.size();++index){
        std::cout<<output[index]<<std::endl;
    }
    return 0;
}