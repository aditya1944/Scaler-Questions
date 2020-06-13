#include<iostream>
#include<vector>
#include<string>
bool isPalindrome(std::string_view input){
    for(int index = 0;index<=input.length()/2;++index){
        //a, b, c, a, d
        //0  1  2  3  4
        if(input[index]!=input[input.size()-1-index]){
            return false;
        }
    }
    return true;
}
void helper(std::string_view input,std::vector<std::string> temp, std::vector<std::vector<std::string> > &returnValue){
    if(input == ""){
        returnValue.push_back(temp);
        return;
    }
    //std::cout<<input<<std::endl;
    // do partitioning at each index 
    for(int length = 1;length<=input.length();++length){
        std::string_view str = input.substr(0,length);
        if(isPalindrome(str)){
            std::vector<std::string> x = temp;
            std::string q(str);
            x.push_back(q);
            helper(input.substr(length),x,returnValue);
        }
    }
}
std::vector<std::vector<std::string> > solve(std::string &str){
    std::vector<std::vector<std::string> > returnValue;
    std::vector<std::string> temp;
    std::string_view sView(str);
    helper(sView,temp,returnValue);
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    std::vector<std::vector<std::string> > output = solve(str);
    for(auto vec:output){
        for(auto x:vec){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
    }
    //std::cout<<isPalindrome(str)<<std::endl;
    return 0;
}