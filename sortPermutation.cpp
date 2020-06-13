#include<iostream>
#include<vector>
int solve(const std::vector<int> &vec){
    int count = 0,returnValue = 0;
    for(int index = 0;index<vec.size();++index){
        if(vec[index]==index+1){
            //this number is correctly placed
            ++returnValue;
        }
    }
    ++returnValue;
    return returnValue;
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