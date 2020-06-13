#include<iostream>
#include<valarray>
#include<climits>
int solve(std::valarray<int> &arr){
    int returnValue = 0;
    int maxTillNow = INT_MIN;
    for(int index = 0;index<arr.size();++index){
        maxTillNow = std::max(arr[index],maxTillNow);
        if(maxTillNow==index){
            ++returnValue;
            maxTillNow = INT_MIN;
        }
        else{
            
        }
    }
    return returnValue;
}
int main(){
    int N;
    std::cin>>N;
    std::valarray<int> arr(N);
    for(int index = 0;index<N;++index){
        std::cin>>arr[index];
    }
    int output = solve(arr);
    std::cout<<output<<std::endl;
    return 0;
}