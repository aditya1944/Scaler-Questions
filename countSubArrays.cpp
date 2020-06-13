#include<iostream>
#include<vector>
#include<unordered_set>
#define mod 1000000007
int updateLeft(int value, std::unordered_set<int> &hash,int left, std::vector<int> &vec){
    while(vec[left]!=value){
        hash.erase(vec[left]);
        ++left;
    }
    hash.erase(vec[left]);
    ++left;
    return left;
}
int solve(std::vector<int> &vec){
    int returnValue = 0;
    std::unordered_set<int> hash;
    int left=0, right=-1, currWindowLength=0;
    while(right+1<vec.size()){
        ++right;
        if(hash.find(vec[right])!=hash.end()){
            //the element is already in set;
            //update left
            left = updateLeft(vec[right], hash, left,vec);
        }
        hash.insert(vec[right]);
        //std::cout<<"left: "<<left<<"right : "<<right<<std::endl;
        currWindowLength = right-left+1;
        returnValue = (returnValue + currWindowLength)%mod;
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