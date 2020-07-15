#include<iostream>
#include<vector>
#include<climits>
int solve(int N,int K){
    //Let F be the floor above which when egg is dropped the egg breaks

    //if no. of floor is 0 or no. of egg is 0
    //then no. of attempts to be made is 0
    if(N==0 || K==0){
        return 0;
    }

    //if no. of floor is 1 and egg is not 0 then total attempts to find F is 1;
    //this is because -> just drop the egg from first floor to know the status of floor
    if(N==1){
        return 1;
    }
    //N is no. of floor and K is no. of eggs
    //row has floors and cols has eggs
    std::vector<std::vector<int> > dp(K+1,std::vector<int>(N+1));

    //initialise base cases
    int floor,egg;
    //if total eggs is 0. then no. of attempts is 0
    for(floor = 0;floor<=N;++floor){
        dp[0][floor] = 0;
    }
    // if total floor is 0. then no. of attempts is 0.
    for(egg = 0;egg<=K;++egg){
        dp[egg][0] = 0;
    }
    // if total egg is 1 then in worst case no. of attempts to be made is equal to floor
    for(floor = 1;floor<=N;++floor){
        dp[1][floor] = floor;
    }
    // if total floor is 1 then no. of attempts is equal to 1
    for(egg=1;egg<=K;++egg){
        dp[egg][1] = 1;
    }
    for(egg = 2;egg<=K;++egg){
        for(floor = 2;floor<=N;++floor){
            // dp[egg][floor]
            int val = INT_MAX;
            for(int temp = 1;temp<=floor;++temp){
                //at each step find whether 
                val = std::min(val, std::max(dp[egg-1][temp-1],dp[egg][floor-temp])+1);
            }
            dp[egg][floor] = val;
        }
    }
    /*for(auto vec: dp){
        for(int val: vec){
            std::cout<<val<<" ";
        }
        std::cout<<std::endl;
    }*/
    //return 1;
    return dp[K][N];
}
int main(){
    int N,K;
    std::cin>>N>>K;
    int output = solve(N,K);
    std::cout<<output<<std::endl;
    return 0;
}