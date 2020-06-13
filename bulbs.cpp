#include<iostream>
#include<vector>
int solve(const std::vector<int> &vec){
    int stateChange = 0,ans = 0;
    for(int index = 0;index<vec.size();++index){
        int currState = vec[index];
        int finalState = (!stateChange%2)?currState:currState^1;
        if(finalState==0){
            ++stateChange;
            ++ans;
        }
    }
    return ans;
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
    return 0;
}