#include<iostream>
#include<queue>
#include<vector>
std::vector<std::string> solve(int N){
    std::vector<std::string> output = {"0"};
    std::queue<std::string> q;
    q.push("1");
    int k = 1;
    while(k<=N){
        std::string str = q.front();
        output.push_back(str);
        q.pop();
        std::string first = str + "0";
        std::string second = str + "1";
        q.push(first);
        q.push(second);
        ++k;
    }
    return output;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> output = solve(N);
    for(auto &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}