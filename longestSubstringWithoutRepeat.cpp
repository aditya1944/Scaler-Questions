#include<iostream>
#include<unordered_set>
int solve(const std::string &str){
    int left = 0,right = -1,currLength = 0,maxLength=-1;
    std::unordered_set<char> hash;
    while(right+1<str.size()){
        if(hash.find(str[right+1])==hash.end()){
            hash.insert(str[right+1]);
            ++right;
        }
        else if(hash.find(str[right+1])!=hash.end()){
            hash.erase(str[left]);
            ++left;
        }
        //std::cout<<"CSsc";
        currLength = right-left+1;
        maxLength = std::max(maxLength, currLength);
    }
    return maxLength;
}
int main(){
    std::string str;
    std::cin>>str;
    int output = solve(str);
    std::cout<<output<<std::endl;
    return 0;
}