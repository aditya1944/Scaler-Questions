#include<iostream>
#include<vector>
int solve(std::vector<int> &vec){
    int returnValue = 0;
    int low = 0,high = vec.size()-1;
    while(low<high){
        int currArea = (high-low)*std::min(vec[low],vec[high]);
        returnValue = std::max(currArea,returnValue);
        if(vec[low]<vec[high]){
            ++low;
        }
        else{
            --high;
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