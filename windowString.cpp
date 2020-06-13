#include<iostream>
#include<unordered_map>
#include<climits>
void initialiseMap(std::string &str,std::unordered_map<char, int> &hashMap){
    for(int index = 0;index<str.length();++index){
        ++hashMap[str[index]];
    }
}
std::string solve(std::string str, std::string pat){
    std::unordered_map<char,int> patHashMap, windowHashMap;
    initialiseMap(pat,patHashMap);
    int left = 0, right = -1, currWindowSize, minWindowSize=INT_MAX,currCount = 0,minLeft, minRight;
    std::string returnString;
    while(right+1<str.size()){
        ++windowHashMap[str[right+1]];
        if(patHashMap.find(str[right+1])!=patHashMap.end() && windowHashMap[str[right+1]]<=patHashMap[str[right+1]]){
            ++currCount;
            //std::cout<<right+1;
        }
        ++right;
        //std::cout<<"Cdcc";
        if(currCount>=pat.size()){
            //std::cout<<"Vddfvdf";
            while(patHashMap.find(str[left])==patHashMap.end() || windowHashMap[str[left]]>patHashMap[str[left]]){
                --windowHashMap[str[left]];
                ++left;
            }
            currWindowSize = right-left+1;
            if(minWindowSize>currWindowSize){
                minWindowSize = currWindowSize;
                //std::cout<<"Vddfvdf";
                minLeft = left;
                minRight = right;
            }
        }
        
    }
    for(int index = minLeft;index<=minRight;++index){
        returnString.push_back(str[index]);
    }
    return returnString;
}
int main(){
    std::string str,pat;
    std::cin>>str>>pat;
    std::string output = solve(str,pat);
    std::cout<<output<<std::endl;
    return 0;
}