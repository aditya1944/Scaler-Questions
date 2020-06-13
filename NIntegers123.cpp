#include<iostream>
#include<queue>
#include<vector>
std::vector<int> solve(int N){
    std::vector<int> returnValue(N);
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    int k = 0;
    while(k<N){
        int top = q.front();
        q.pop();
        returnValue[k] = top;
        q.push(top*10 + 1);
        q.push(top*10 + 2);
        q.push(top*10 + 3);
        ++k;
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> output = solve(N);
    for(int &x: output){
        std::cout<<x<<std::endl;
    }
    return 0;
}