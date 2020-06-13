#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
int solve(const std::vector<int> &vec){
    int minDistance = INT_MAX, currDistance;
    std::unordered_map<int,int> hash;
    for(int index = 0;index<vec.size();++index){
        hash.insert(std::make_pair(vec[index],index));
    }
    for(int index = 0;index<vec.size();++index){
        int currVal = vec[index];
        currDistance = abs(hash[currVal]-index);
        if(currDistance!=0){
            minDistance = std::min(minDistance,currDistance);
        }
    }
    if(minDistance==INT_MAX){
        minDistance = -1;
    }
    return minDistance;
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