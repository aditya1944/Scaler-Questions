#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
int solve(std::vector<std::string> &vec){
    //triplet sum 1<sum<2
    //make 3 arr
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<" ";
    return 0;
}