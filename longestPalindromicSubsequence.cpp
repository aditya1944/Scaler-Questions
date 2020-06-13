#include<iostream>
#include<unordered_map>
#include<vector>
bool checkPalindrome(const std::string str){
    const int n = str.length();
    for(int index = 0;index<n/2;++index){
        if(str[index]!=str[n-index-1]){
            return false;
        }
    }
    return true;
}
int findMax(std::string str,int currIndex,std::unordered_map<std::string,std::vector<int> >& dp){
    if(currIndex==str.length()){
        //subsequence created => check if it is palindrome
        if(checkPalindrome(str)){
            return str.length();
        }
        return 0;
    }
    if(dp.find(str)!=dp.end()){
        if(dp[str][0]==currIndex){
            return dp[str][1];
        }
    }
    //element of choice
    //take the element at current Index or not
    //1. taking the element at current Index
    std::string original = str;
    int rightResult = findMax(str,currIndex+1,dp);
    str.erase(currIndex,1);
    int leftResult = findMax(str,currIndex,dp);
    int returnValue = std::max(rightResult,leftResult);
    std::vector<int> temp = {currIndex,returnValue};
    dp.insert(std::make_pair(original,temp));
    return returnValue;
}
int solve(std::string A) {
    /*int currIndex = 0;
    std::unordered_map<std::string,std::vector<int> >dp;
    int maxLength = findMax(A,currIndex,dp);
    return maxLength;*/
    const int size = A.length();
    std::vector<std::vector<int> > dp(size, std::vector<int>(size,1));
    //base cases
    for(int distance = 1;distance<size;++distance){
        int rowIndex;
        for(int colIndex = distance;colIndex<size;++colIndex){
            //std::cout<<distance<<"&&"<<colIndex<<std::endl;
            rowIndex = colIndex-distance;
            if(rowIndex==colIndex){
                continue;
            }
            int temp;
            if(A[rowIndex]==A[colIndex]){
                if(distance==1){
                    temp=2;
                }
                else{
                    temp=2 + dp[rowIndex+1][colIndex-1];
                }
            }
            else{
                temp = std::max(dp[rowIndex+1][colIndex],dp[rowIndex][colIndex-1]);
            }
            dp[rowIndex][colIndex] = temp;
        }
    }
    /*for(int rowIndex = 0;rowIndex<size;++rowIndex){
        for(int colIndex = 0;colIndex<size;++colIndex){
            std::cout<<dp[rowIndex][colIndex]<<" ";
        }
        std::cout<<std::endl;
    }*/
    return dp[0][size-1];
}
int main(){
    std::string str;
    std::cin>>str;
    std::cout<<solve(str)<<std::endl;
    return 0;
}