#include<iostream>
#include<vector>
std::vector<int> solve(int K,std::vector<std::vector<int> >&queries){
    std::vector<int> output(K,0);
    for(int index = 0;index<queries.size();++index){
        int lowIndex = queries[index][0]-1;
        int highIndex = queries[index][1]-1;
        int val = queries[index][2];
        if(highIndex==K-1){
            output[lowIndex]+=val;
        }
        else{
            output[lowIndex]+=val;
            output[highIndex+1]-=val;
        }
    }
    for(int index = 1;index<K;++index){
        output[index]+=output[index-1];
    }
    return output;
}
int main(){
    int N,K;
    std::cin>>N>>K;
    std::vector<std::vector<int> > queries(N,std::vector<int>(3,0));
    for(int index = 0;index<N;++index){
        std::cin>>queries[index][0]>>queries[index][1]>>queries[index][2];
    }
    std::vector<int> result; 
    result = solve(K,queries);
    for(int index = 0;index<result.size();++index){
        std::cout<<result[index]<<" ";
    }
    return 0;
}