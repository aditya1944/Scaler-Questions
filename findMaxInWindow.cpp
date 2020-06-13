#include<iostream>
#include<vector>
#include<queue>
std::vector<int> findMaxWindow(std::vector<int> &vec, size_t windowSize){
    std::deque<int> d;
    std::vector<int> returnValue;
    for(int index = 0;index<windowSize;++index){
        if(d.empty()){
            d.push_back(index);
        }
        else if(vec[d.back()]<vec[index]){
            while(!d.empty() && vec[d.back()]<vec[index]){
                d.pop_back();
            }
            d.push_back(index);
        }
        else{
            d.push_back(index);
        }
    }
    returnValue.push_back(vec[d.front()]);
    for(int index = windowSize;index<vec.size();++index){
        if(d.front()<index){
            d.pop_front();
        }
        if(d.empty()){
            d.push_back(index);
        }
        else if(vec[d.back()]<vec[index]){
            while(!d.empty() && vec[d.back()]<vec[index]){
                d.pop_back();
            }
            d.push_back(index);
        }
        else{
            d.push_back(index);
        }
        returnValue.push_back(vec[d.front()]);
    }
    return returnValue;
}
int main(){
    size_t N,K;
    std::cin>>N>>K;
    std::vector<int> vec(N);
    for(size_t index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    std::vector<int> returnValue = findMaxWindow(vec,K);
    for(auto val: returnValue){
        std::cout<<val<<" ";
    }
    return 0;
}