#include<iostream>
#include<vector>
int solve(int K, const std::string &str){
    std::vector<int> hash(26,0);
    for(int index = 0;index<str.length();++index){
        char ch = str[index];
        hash[ch-'a']+=1;
    }
    for(int index = 0;index<26;++index){
        if(hash[index]%K!=0){
            return -1;
        }
    }
    return 1;
}
int main(){
    int K;
    std::string str;
    std::cin>>K>>str;
    int output = solve(K,str);
    std::cout<<output<<std::endl;
    return 0;
}