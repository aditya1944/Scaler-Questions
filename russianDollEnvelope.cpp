#include<iostream>
#include<vector>
#include<algorithm>
bool compare(const std::vector<int> &v1, const std::vector<int> &v2){
    return v1[0]<v2[0];
}
int solve(std::vector<std::vector<int> >&A){
    //find longest increasing subsequence based on A[1];
    std::vector<int> dp(A.size());
    std::sort(A.begin(),A.end(),compare);
    for(int index = 0;index<A.size();++index){
        for(int j = index-1;j>=0;--j){
            if(A[j][1]<A[index][1])
                dp[index] = std::max(dp[index],dp[j]+1);
        }
    }
    return dp[A.size()-1];
}
int main(){
    //std::vect
    return 0;
}