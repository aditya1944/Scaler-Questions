#include<iostream>
#include<vector>
#define mod 1000000007
int solve(std::vector<int> &A, int B){
    std::vector<int> dp(A.size(),0);
    dp[0] = 0;
    dp[1] = 1;
}
int main(){
    int N,B;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::cin>>B;
    int output = solve(vec,B);
    std::cout<<output<<std::endl;
    return 0;
}