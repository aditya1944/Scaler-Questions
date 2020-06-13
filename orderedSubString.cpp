#include<iostream>
#include<vector>
#include<algorithm>
bool compare(std::string &s1, std::string &s2){
    return s1.size()<s2.size();
}
std::vector<std::string> solve(std::vector<std::string> &vec){
    std::sort(vec.begin(),vec.end(),compare);
    for(int index = 0;index<vec.size()-1;++index){
        if(vec[index+1].find(vec[index])==std::string::npos){
            std::vector<std::string> returnValue = {"NO"};
            return returnValue;
        }
    }
    return vec;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<std::string> output = solve(vec);
    for(auto &x: output){
        std::cout<<x<<std::endl;
    }
    return 0;
}