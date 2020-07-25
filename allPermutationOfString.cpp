#include<iostream>
void helper(std::string &str, int left, int right){
    if(left==right){
        std::cout<<str<<std::endl;
        return ;
    }
    for(int index = left;index<=right;++index){
        std::swap(str[left],str[index]);
        helper(str,left+1,right);
        std::swap(str[left],str[index]);
    }
}
void printPermutation(std::string &str){
    helper(str,0,str.size()-1);
}
int main(){
    std::string str = "1234";
    printPermutation(str);
    return 0;
}