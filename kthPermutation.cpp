#include<iostream>
#include<vector>
#include<algorithm>
int factorial(int N, int K){
    std::vector<long long> dp(N+1);
    dp[0] = dp[1] = 1;
    for(int index = 2;index<=N;++index){
        dp[index] = dp[index-1] * index;
        if(dp[index]>K){
            return K+2;
        }
    }
    return dp[N];
}
std::vector<long long> findFactorad(int num, int size){
    std::vector<long long> returnValue(size, 0);
    int index = 0;
    int divisor = 1;
    while(num!=0){
        int remainder = num%divisor;
        returnValue[index] = remainder;
        ++index;
        num = num/divisor;
        ++divisor;
    }
    return returnValue;
}
std::string solve(int N, int K){
    //modify K;
    K = K-1;
    std::string output = "";
    std::vector<long long> numVec(N);
    for(int num = 1;num<=N;++num){
        numVec[num-1] = num;
    }
    int fact = factorial(N,K);
    int temp = K%fact;
    if(temp!=0){
        K = temp;
    }
    //new K value 
    //now find Kth permutation
    //convert K in factorial number system
    std::vector<long long> factorad = findFactorad(K, N);
    
    std::reverse(factorad.begin(), factorad.end());
    /*for(int &x:factorad){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;*/
    for(int index= 0;index<factorad.size();++index){
        output+=std::to_string(numVec[factorad[index]]);
        numVec.erase(numVec.begin() + factorad[index]);
    }
    return output;
}
int main(){
    int N,K;
    std::cin>>N>>K;
    std::string output = solve(N,K);
    std::cout<<output<<std::endl;
    /*std::vector<int> temp = findFactorad(23);
    for(int &x:temp){
        std::cout<<x<<" ";
    }*/
    return 0;
}