#include<iostream>
#include<algorithm>
#include<queue>
int solve(std::vector<int> &vec){
    int returnValue;
    std::queue<int> q;
    std::sort(vec.begin(),vec.end());
    q.push(vec[0]);
    for(int index = 1;index<vec.size();++index){
        int currVal = vec[index];
        int topValue = q.front();
        if(2*topValue<=currVal){
            q.pop();
        }
        q.push(currVal);
    }
    returnValue = q.size();
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index= 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}