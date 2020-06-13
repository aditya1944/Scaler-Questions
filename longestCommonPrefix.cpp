#include<iostream>
#include<unordered_map>
#include<vector>
std::string solve(std::vector<std::string> &arr){
    std::string returnValue = arr[0];
    for(int index = 1;index<arr.size();++index){
        std::string currStr = arr[index];
        int j = 0;
        while(j<std::min(returnValue.size(), currStr.size()) && returnValue[j]==currStr[j]){
            ++j;
        }
        returnValue.erase(j);
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::string output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}
//3 abab ab abcd