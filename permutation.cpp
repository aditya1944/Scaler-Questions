#include<iostream>
#include<vector>
#include<string>
void helper(std::string &input, std::string output,std::vector<std::vector<int> > &returnValue){
    if(input.size()==0){
        //std::cout<<"dddfv"<<std::endl;
        std::vector<int> vec(output.begin(), output.end());
        returnValue.push_back(vec);
        return;
    }
    for(int index = 0;index<input.size();++index){
        std::string temp = input;
        helper(temp.erase(index,1), output + input[index], returnValue);
    }
}
std::vector<std::vector<int> > solve(std::vector<int> &arr){
    std::vector<std::vector<int> > returnValue;
    std::string str(arr.begin(), arr.end());
    std::string output = "";
    helper(str,output, returnValue);
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    std::vector<std::vector<int> > output = solve(arr);
    for(auto x: output){
        for(auto y:x){
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}