#include<iostream>
#include<string_view>
bool isPalindrome(std::string_view &str){
    for(int index = 0;index<str.length()/2;++index){
        if(str[index]!=str[str.length()-1-index]){
            return false;
        }
    }
    return true;
}
int solve(std::string &input){
    int returnValue=0;
    std::string_view s1(input);
    for(int index = input.size()-1;index>=0;--index){
        if(isPalindrome(s1)){
            break;
        }
        else{
            int length = s1.length();
            s1 =  s1.substr(0,length-1);
            ++returnValue;
        }
    }
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    int output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}