#include<iostream>
#include<unordered_map>
void updateLeft(std::unordered_map<char, int> &windowMap, std::string &str2, int &left,char val){
    while(str2[left]!=val){
        --windowMap[str2[left]];
        ++left;
    }
    --windowMap[str2[left]];
    ++left;
}
int solve(std::string &str1,std::string &str2){
    std::unordered_map<char,int> hashMap;//store frequency of character in hash
    std::unordered_map<char,int> windowMap;//store frequency of character in window
    int returnValue = 0;
    //find str1 in str2
    for(int index = 0;index<str1.length();++index){
        ++hashMap[str1[index]];
    }
    //will use sliding window
    int left = 0, right=-1,currCount=0;
    while(right+1<str2.length()){
        ++right;
        ++windowMap[str2[right]];
        if(hashMap.find(str2[right])!=hashMap.end()){
            if(windowMap[str2[right]]<=hashMap[str2[right]]){
                ++currCount;
            }
            else{
                updateLeft(windowMap,str2,left,str2[right]);
                currCount = right-left+1;
            }
        }
        else{
            windowMap.clear();
            left = right+1;
            currCount = 0;
        }
        if(currCount==str1.size()){
            ++returnValue;
            --windowMap[str2[left]];
            ++left;
            --currCount;
        }
    }
    return returnValue;
}
int main(){
    std::string str1, str2;
    std::cin>>str1>>str2;
    int output = solve(str1,str2);
    std::cout<<output<<std::endl;
    return 0;
}