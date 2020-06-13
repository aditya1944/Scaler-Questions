#include<iostream>
#include<vector>
#define mod 1000000007
int solve(int A){
    int points = 2 * A;
    std::vector<int> dp(points+1,1);
    for(int point = 4;point<=points;point+=2){
        int temp = 0;
        int leftPoints = 0;
        int rightPoints = point-2;
        for(int loop = 1;loop<=point/2;++loop){
            temp = ((long long)temp + ((long long)dp[leftPoints]*(long long)dp[rightPoints])%mod)%mod;
            leftPoints+=2;
            rightPoints-=2;
        }
        dp[point] = temp;
    }
    return dp[points];
}
int main(){
    int A;
    std::cin>>A;
    int output = solve(A);
    std::cout<<output<<std::endl;
    return 0;
}