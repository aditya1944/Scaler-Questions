#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
void helper(std::vector<int> &arr, int currIndex, int currSum, int totalSum,std::vector<int> output,std::vector<std::vector<int> >& result, std::unordered_set<std::string> &buffer){
    if(currSum==totalSum){
        std::string s(output.begin(), output.end());
        if(buffer.find(s)==buffer.end()){
            //not present
            buffer.insert(s);
            result.push_back(output);
        }
        return;
    }
    else if(currIndex>=arr.size() || currSum>totalSum){
        return;
    }
    //do not take this number
    helper(arr, currIndex+1, currSum, totalSum, output,result, buffer);
    //take this number
    output.push_back(arr[currIndex]);
    helper(arr,currIndex+1,currSum+arr[currIndex],totalSum,output,result, buffer);
}
std::vector<std::vector<int> > solve(std::vector<int> &arr, int K){
    std::vector<std::vector<int> > returnValue;
    std::vector<int> num;
    std::sort(arr.begin(),arr.end());
    std::unordered_set<std::string> buffer; 
    helper(arr, 0,0, K,num,returnValue, buffer);
    std::reverse(returnValue.begin(),returnValue.end());
    return returnValue;
}
int main(){
    int N,K;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::cin>>K;
    std::vector<std::vector<int> > output = solve(arr,K);
    for(auto x: output){
        for(auto y:x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}