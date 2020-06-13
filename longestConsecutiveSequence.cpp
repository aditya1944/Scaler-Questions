#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
int helper(std::unordered_set<int> &hash, int currVal){
    int length = 0;
    while(hash.find(currVal)!=hash.end()){
        //hash.erase(currVal);
        ++currVal;
        ++length;
    }
    return length;
}
int solve(std::vector<int> vec){
    int returnValue = INT_MIN;
    std::unordered_set<int> hash;
    for(int index = 0;index<vec.size();++index){
        hash.insert(vec[index]);
    }
    for(int index = 0;index<vec.size();++index){
        int currVal = vec[index];
        if(hash.find(currVal-1)==hash.end()){
            int currlength = helper(hash,currVal);
            returnValue = std::max(returnValue,currlength);
        }
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    std::cout<<output<<std::endl;
    return 0;
}