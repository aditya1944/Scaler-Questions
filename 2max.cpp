#include<iostream>
#include<vector>
#include<climits>
int solve(std::vector<int> &arr){
    int max1 = arr[0];
    int max2 = INT_MIN;
    for(int index = 1;index<arr.size();++index){
        if(arr[index]>max1){
            max2 = max1;
            max1 = arr[index];
        }
        else if(arr[index]<max1 && arr[index]>max2){
            max2 = std::max(arr[index],max2);
        }
    }
    return max2;
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
}