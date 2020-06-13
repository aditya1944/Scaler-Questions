#include<iostream>
#include<vector>
int solve(const std::vector<int> &gas, const std::vector<int> &gasTobeSpent){
    if(gasCost.size()==1){
        return 0;
    }
    int returnValue;
    int start = 0,end = 0, currGasLeft = 0;
    while(1){
        currGasLeft = gasTobeSpent[end] - gas[end];
        if(currGasLeft<0){
            
        }
    }
    return returnValue;
}
int main(){
    int N;  
    std::cin>>N;
    std::vector<int> gasCost(N);
    std::vector<int> gasTobeSpent(N);
    for(int index = 0;index<N;++index){
        std::cin>>gasCost[index];
    }
    for(int index = 0;index<N;++index){
        std::cin>>gasTobeSpent[index];
    }
    int output = solve(gasCost, gasTobeSpent);
    std::cout<<output<<std::endl;
    return 0;
}