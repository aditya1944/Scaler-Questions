#include<iostream>
#include<vector>
#include<algorithm>
void solve(std::vector<int> &vec,int currIndex,std::vector<int> output, int K, std::vector<std::vector<int> > &returnValue){
    if(output.size()==K){
        std::sort(output.begin(),output.end());
        returnValue.push_back(output);
        return;
    }
    if(currIndex==vec.size()){
        return;
    }
    //take the element at currIndex or not
    solve(vec, currIndex+1, output, K,returnValue);
    output.push_back(vec[currIndex]);
    solve(vec,currIndex+1, output, K,returnValue);
}
std::vector<std::vector<int> > solve(int N, int K){
    //K is the max number
    std::vector<std::vector<int> > returnValue;
    std::vector<int> arr(N,0);
    for(int index = 0;index<N;++index){
        arr[index] = index+1;
    }
    std::vector<int> output;
    solve(arr,0,output,K,returnValue);
    std::reverse(returnValue.begin(),returnValue.end());
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N>>K;
    std::vector<std::vector<int> > output;
    output = solve(N, K);
    for(auto &x:output){
        for(int &y:x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}