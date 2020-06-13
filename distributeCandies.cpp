#include<iostream>
#include<vector>
int solve(std::vector<int> &vec){
    if(vec.size()==1){
        return 1;
    }
    const int size = vec.size();
    std::vector<int> candies(size);
    candies[0] = 1;
    //traversed left
    for(int index = 1;index<size;++index){
        if(vec[index-1]>=vec[index]){
            candies[index] = 1;
        }
        else{
            candies[index]=candies[index-1]+1;
        }
    }
    //traversed right
    int returnValue = candies[candies.size()-1];
    for(int index = size-2;index>=0;--index){
        //compare the candies on left
        if((vec[index]>vec[index+1]) && candies[index]<=candies[index+1]){
            candies[index] = candies[index+1]+1;
        }
        returnValue+=candies[index];
    }
    return returnValue;
}
int main(){
    int N;
    scanf("%d",&N);
    std::vector<int> vec(N);
    for(int index = 0;index<N;++index){
        std::cin>>vec[index];
    }
    int output = solve(vec);
    printf("%d",output);
    return 0;
}