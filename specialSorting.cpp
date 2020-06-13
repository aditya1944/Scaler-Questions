#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
std::vector<int> solve(std::vector<int> &vec1, std::vector<int> &vec2){
    std::unordered_map<int,int> hash;
    for(int index = 0;index<vec1.size();++index){
        ++hash[vec1[index]];
    }
    std::vector<int> returnValue;
    for(int index = 0;index<vec2.size();++index){
        int currVal = vec2[index];
        if(hash.find(currVal)!=hash.end()){
            for(int fre = 1;fre<=hash[currVal];++fre){
                returnValue.push_back(currVal);
            }
            hash.erase(currVal);
        }
    }
    int sortingStartIndex = returnValue.size();
    for(auto &x:hash){
        for(int fre = 1;fre<=x.second;++fre){
            returnValue.push_back(x.first);
        }
    }
    std::sort(returnValue.begin()+sortingStartIndex,returnValue.end());
    return returnValue;
}
int main(){
    int N1, N2;
    std::cin>>N1>>N2;
    std::vector<int> vec1(N1, 0);
    std::vector<int> vec2(N2, 0);
    for(int index = 0;index<N1;++index){
        std::cin>>vec1[index];
    }
    for(int index = 0;index<N2;++index){
        std::cin>>vec2[index];
    }
    std::vector<int> output = solve(vec1,vec2);
    for(int&x:output){
        std::cout<<x<<" ";
    }
    return 0;
}