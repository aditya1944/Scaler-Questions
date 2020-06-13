#include<iostream>
#include<vector>
#include<climits>
int solve(const std::vector<int> &vec){
    //no of matrices possible is size - 1;
    const int n = vec.size() - 1;
    std::vector<std::vector<int> > dp(n,std::vector<int>(n,0));
    for(int length = 2;length<=n;++length){
        for(int start = 0;start<=n-length;++start){
            int end = start + length-1;
            dp[start][end] = INT_MAX;
            for(int k=start;k<end;++k){
                dp[start][end] = std::min(dp[start][end],dp[start][k] + dp[k+1][end] + vec[start] * vec[k+1] * vec[end+1]);
            }
        }
    }
    return dp[0][n-1];
}
//1 2 3 4 5 6 7
//(1 2 3 4)
//
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