#include<iostream>
#include<vector>
int solve(const std::string &str){
    int returnValue = 0;
    int ansLeft = 0, leftBoundary = 0,ansRight = 0, rightBoundary = str.size()-1;
    //traverse from left
    for(int index = 0;index<str.size();++index){
        if(str[index]=='0'){
            ansLeft+=(index-leftBoundary);
            ansRight+=(rightBoundary-index);
            --rightBoundary;
            ++leftBoundary;
        }
    }
    returnValue = std::min(ansRight, ansLeft);
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    int output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}