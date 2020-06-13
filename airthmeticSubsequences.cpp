#include<iostream>
#include<vector>
#include<unordered_set>
int solve(vector<int> &A) {
    std::vector<std::unordered_map<long long,int> > dp(A.size());
    int ans = 0;
    for(int i = 1;i<A.size();++i){
        for(int j = i-1;j>=0;--j){
            long long diff = (long long)A[j]-(long long)A[i];
            // at every state we are calculating no. of weak airthemtic subsequences(length==2);
            dp[i][diff]+=(dp[j][diff] + 1);
            //1 is added because every two number form airthmetic subsequence 
            ans+=dp[j][diff];
        }
    }
    return ans;
}