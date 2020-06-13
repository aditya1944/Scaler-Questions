#include<iostream>
#include<vector>
#include<algorithm>
void helper( std::string input, std::vector<std::string> &returnValue){
    if(input.empty()){
        returnValue.push_back("");
        return;
    }
    std::string smallString = input.substr(1);
    helper(smallString, returnValue);
    int originalSize = returnValue.size();
    for(int index = 0;index<originalSize;++index){
        std::string temp = input[0] + returnValue[index];
        returnValue.push_back(temp);
    }
}
std::vector<std::vector<int> > solve(std::vector<int> &arr){
   std::string str(arr.begin(),arr.end());
   std::vector<std::string> powerSet;
   std::vector<std::vector<int> > returnValue;
   helper(str, powerSet);
   std::sort(powerSet.begin(),powerSet.end());
   for(int index = 0;index<powerSet.size();++index){
       std::vector<int> temp(powerSet[index].begin(),powerSet[index].end());
       returnValue.push_back(temp);
   }
   return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::vector<std::vector<int> > output = solve(arr);
    for(auto x: output){
        for(auto y:x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}