#include<bits/stdc++.h>
using namespace std;
long long calculateHash(std::string str){
        std::sort(str.begin(),str.end());
        long long hashValue = 0,multiplier = 1;
        for(int index = 0;index<str.length();++index){
            hashValue+=(multiplier * (str[index] - '0'+1));
            multiplier*=2;
        }
        return hashValue;
}
int main(){
    std::cout<<calculateHash("mai");
    return 0;
}