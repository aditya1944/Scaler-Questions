#include<iostream>
#include<vector>
#include<unordered_map>
int helper(std::string A,std::unordered_map<int,int> &dp){
    if(A.size()>=1 && A[0]=='0'){
        return 0;
    }
    if(A.size()==0){
        return 1;
    }
    if(A.size()==1){
        return 1;
    }
    if(dp.find(A.size())!=dp.end()){
        return dp[A.size()];
    }
    int ways = helper(A.substr(1),dp);
    if(A.size()>1){
        int num = std::stoi(std::to_string(A[0]-'0') + std::to_string(A[1]-'0'));
        if(num>0 && num<27){
            ways+=helper(A.substr(2),dp);
        }
    }
    dp.insert(std::make_pair(A.size(),ways));
    return ways;
}
int numDecodings(std::string A){
    std::unordered_map<int, int> dp;
    int ways = helper(A,dp);
    return ways;
}
int main(){
    std::string str;
    std::cin>>str;
    int output = numDecodings(str);
    std::cout<<output<<std::endl;
    return 0;
}