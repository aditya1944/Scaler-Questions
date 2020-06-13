#include<iostream>
#include<vector>
#include<unordered_map>
int updateLeft(std::unordered_map<char, int> &mp, int left, const std::string &str, char ch, int &currLength){
    while(str[left]!=ch){
        --mp[str[left]];
        ++left;
        --currLength;
    }
    //left is now at that index 
    --currLength;
    --mp[str[left]];
    ++left;
    return left;
}
std::vector<int> solve(const std::string &str, const std::string &patt){
    std::vector<int> returnValue;
    std::unordered_map<char, int> hashMap, windowMap;
    for(int index = 0;index<patt.size();++index){
        ++hashMap[str[index]];
    }
    int left = 0, right = -1;
    int currLength = 0;
    while(right+1<str.size()){
        ++right;
        char ch = str[right];
        if(hashMap.find(ch)==hashMap.end()){
            //curr character
            left = right+1;
            windowMap.clear();
            currLength = 0;
        }
        else{
            ++windowMap[ch];
            ++currLength;
            if(windowMap[ch]>hashMap[ch]){
                left = updateLeft(windowMap, left, str, ch,currLength);
            }
        }
        if(currLength==patt.size()){
            //std::cout<<"left : "<<left<<std::endl;
            returnValue.push_back(right-patt.size()+1);
        }
    }
    return returnValue;
}
int main(){
    std::string str1, str2;
    std::cin>>str1>>str2;
    std::vector<int> output = solve(str1, str2);
    for(int &x: output){
        std::cout<<x<<" ";
    }
    return 0;
}