#include<iostream>
#include<queue>
#include<unordered_map>
std::string solve(const std::string &str){
    std::string returnValue = "";
    std::unordered_map<char, int> hashMap;
    std::queue<char> q;
    for(int index = 0;index<str.length();++index){
        char ch = str[index];
        ++hashMap[ch];
        if(hashMap[ch]==1){
            q.push(ch);
        }
        while(hashMap[q.front()]>1){
            q.pop();
        }
        if(q.empty()){
            returnValue.push_back('#');
        }
        else{
            returnValue.push_back(q.front());
        }
    }
    return returnValue;
}
int main(){
    std::string str;
    std::cin>>str;
    std::string output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}