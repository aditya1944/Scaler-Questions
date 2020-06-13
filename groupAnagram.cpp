#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
bool compare(const std::vector<int> &v1, const std::vector<int> &v2){
    return v1[0]<v2[0];
}
std::vector<std::vector<int> > solve(const std::vector<std::string> &arr){
    std::unordered_map<std::string, std::vector<int> > hashMap;
    std::vector<std::vector<int> >returnValue;
    for(int index = 0;index<arr.size();++index){
        std::string currString = arr[index];
        std::sort(currString.begin(),currString.end());
        hashMap[currString].push_back(index+1);
    }
    for(auto x:hashMap){
        std::vector<int> temp = x.second;
        returnValue.push_back(temp);
    }
    sort(returnValue.begin(),returnValue.end(),compare);
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<std::string> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::vector<std::vector<int> > output = solve(arr);
    for(auto x: output){
        for(int &y: x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }//*/
    /*std::string str;
    std::cin>>str;
    std::cout<<computeHash(str)<<std::endl;*/
    return 0;
}