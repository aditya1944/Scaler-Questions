#include<iostream>
#include<math.h>
long long computeHash(const std::string &str){
    long long hash = 0,multiplier=1;
    for(int index = 0;index<str.length();++index){
        hash = hash + str[index]*multiplier;
        multiplier = multiplier*2;
    }
    //std::cout<<hash;
    return hash;
}
int solve(const std::string &str, const std::string &subStr){
    if(subStr.empty() || str.empty()){
        return -1;
    }
    int returnValue;
    int currLength = 0,currHash = 0,multiplier = 1;
    int subStrHash = computeHash(subStr);
    for(int index = 0;index<str.length();++index){
        currLength = index+1;
        if(currLength<=subStr.length()){
            currHash += (multiplier * str[index]);
            multiplier = multiplier * 2;
        }
        else{
            currHash = currHash - (str[index-subStr.length()]);
            currHash = currHash/2;
            currHash += str[index] * std::pow(2,subStr.length()-1);
        }
        if(currHash==subStrHash){
            returnValue = index - subStr.length()+1;
            return returnValue;
        }
    }
    return -1;
}
int main(){
    std::string substr, str;
    std::cin>>substr>>str;
    int output = solve(str,substr);
    std::cout<<output<<std::endl;
    return 0;
}