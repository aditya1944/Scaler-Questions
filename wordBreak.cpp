#include<iostream>
#include<vector>
#include<string_view>
#include<unordered_set>
int wordBreak(const std::string &str,const std::vector<std::string> &B){
    std::unordered_set<std::string> hash(B.begin(),B.end());
    std::vector<bool> dp(str.size(),false);
    int index = 0;
    for(;index<str.size();++index){
        std::string subStr = str.substr(0,index+1);
        if(hash.find(subStr)!=hash.end()){
            dp[index] = true;
            break;
        }
    }
    /*if(index==str.size()){
        return dp[dp.size()-1];
    }*/
    for(;index<str.size();++index){
        int j = index-1;
        while(j>=0){
            if(dp[j]){
                std::string subStr = str.substr(j,index - j+1);
                if(hash.find(subStr)!=hash.end()){
                    dp[index] = true;
                    break;
                }
            }
            --j;
        }
    }
    return dp[dp.size()-1];
}
int main(){
    
    return 0;
}