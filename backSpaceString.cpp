#include<iostream>
using namespace std;
bool backspaceCompare(string S, string T) {
    int solidL1 = -1,solidL2 = -1;
    for(int index = 0;index<S.length();++index){
        if(S[index]=='#' && solidL1!=-1){
            solidL1-=1;
        }
        else if(S[index]!='#'){
            S[solidL1+1] = S[index];
            ++solidL1;
        }
    }
    for(int index = 0;index<T.length();++index){
        if(T[index]=='#' && solidL2!=-1){
            solidL2-=1;
        }
        else if(T[index]!='#'){
            T[solidL2+1] = T[index];
            ++solidL2;
        }
    }
    if(solidL1!=solidL2){
        return false;
    }
    if(solidL1==-1 && solidL2){
        return true;
    }
    for(int i=0;i<solidL1;++i){
        if(S[i]!=T[i]){
            return false;
        }
    }
    return true;
}
int main(){
    std::string str1, str2;
    std::cin>>str1>>str2;
    std::cout<<backspaceCompare(str1, str2)<<std::endl;
    return 0;
}