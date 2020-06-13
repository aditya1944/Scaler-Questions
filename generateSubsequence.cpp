#include<iostream>
void solve(std::string str,int currIndex){ 
    if(currIndex==str.length()){
        std::cout<<str<<std::endl;
        return ;
    }
    solve(str,currIndex+1);
    str.erase(currIndex,1);
    solve(str,currIndex);
}
int main(){
    std::string str;
    std::cin>>str;
    solve(str,0);
    return 0;
}