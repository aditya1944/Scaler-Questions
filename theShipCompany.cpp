#include<iostream>

#include<queue>
std::vector<int> solve(int A,int N, const std::vector<int> &vec){
    std::priority_queue<int> maxHeap(vec.begin(),vec.end());
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap(vec.begin(),vec.end());
    //calculate maximum
    int maximumValue = 0,minimumValue = 0;
    int noOfPeople = A;
    while(noOfPeople--){
        int top = maxHeap.top();
        maxHeap.pop();
        maximumValue+=top;
        maxHeap.push(top-1);
    }
    noOfPeople = A;
    while(noOfPeople--){
        int top = minHeap.top();
        minHeap.pop();
        minimumValue+=top;
        minHeap.push(top-1);
    }
    std::vector<int> returnValue(2);
    returnValue[0] = maximumValue;
    returnValue[1] = minimumValue;
    return returnValue;
}
int main(){
    int N,A;
    std::cin>>A>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> output = solve(A,N,vec);
    std::cout<<output[0]<<output[1]<<std::endl;
    return 0;
}