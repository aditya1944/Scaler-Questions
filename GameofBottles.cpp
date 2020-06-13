#include<iostream>
#include<vector>
#include<map>
int solve(std::vector<int> &vec){
    int returnValue = 0;
    std::map<int, int> mp;
    for(int index = 0;index<vec.size();index){
        ++mp[vec[index]];
        returnValue = std::max(returnValue,mp[vec[index]]);
    }
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