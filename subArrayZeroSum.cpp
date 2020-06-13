#include<iostream>
#include<unordered_set>
#include<vector>
int solve(const std::vector<int> &vec){
    int size = vec.size();
    std::unordered_set<int> se;
    int currSum = 0;
    for(int index = 0;index<size;++index){
        currSum = vec[index] + currSum;
        if(se.find(currSum)!=se.end() || currSum==0 || vec[index]==0){
            return 1;
        }
        se.insert(currSum);
    }
    return 0;
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